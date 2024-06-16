/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:13:46 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/16 15:41:32 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

static	void	get_from_here_doc(int pipe_fds[2], char *limiter)
{
	char	*line;

	line = NULL;
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
		{
			free(line);
			break ;
		}
		write(pipe_fds[1], line, ft_strlen(line));
		free(line);
	}
	close(pipe_fds[1]);
}

static	void	dup_file_descriptor(char	*file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	close(fd);
}

// static	void	exec(char **argv, char **envp, int pipe_fds[2])
// {
// 	char	*command_path;
// 	char	*command;
// 	char	**arguments;

// 	command_path = NULL;
// 	command = NULL;
// 	arguments = NULL;
// 	if (close(pipe_fds[0]) == -1)
// 	{
// 		perror("close");
// 		exit(EXIT_FAILURE);
// 	}
// 	if (dup2(pipe_fds[1], STDOUT_FILENO) == -1)
// 	{
// 		perror("dup2");
// 		exit(EXIT_FAILURE);
// 	}
// 	close(pipe_fds[1]);
// 	command = get_command(argv[2]);
// 	command_path = get_command_path(envp, command);
// 	free(command);
// 	arguments = get_com_args(argv[2]);
// 	exec_command(command_path, arguments, envp);
// }

void	in_process(char **argv, char **envp, int pipe_fds[2])
{
	char	*file_name;

	file_name = argv[1];
	if (ft_strncmp(file_name, "here_doc", 8) == 0)
		get_from_here_doc(pipe_fds, argv[2]);
	else
		dup_file_descriptor(file_name);
	//exec(argv, envp, pipe_fds);
}
