/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:48:23 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/30 17:16:45 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void	get_from_here_doc(int fds[2], char *limiter)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0
			&& line[ft_strlen(limiter)] == '\n')
		{
			free(line);
			break ;
		}
		write(fds[1], line, ft_strlen(line));
		free(line);
	}
	close(fds[1]);
}

void	handle_here_doc(int argc, char **argv, char **envp)
{
	int	pipefd[2];
	int	infile;

	if (pipe(pipefd) == -1)
		ft_error(PIPE_CREATE_ERR, PIPE_CREATE_STAT);
	if (fork() == 0)
	{
		close(pipefd[0]);
		get_from_here_doc(pipefd, argv[2]);
		exit(EXIT_SUCCESS);
	}
	close(pipefd[1]);
	wait(NULL);
	infile = pipefd[0];
	handle_commands(infile, argv + 3, argv[argc - 1], envp);
}
