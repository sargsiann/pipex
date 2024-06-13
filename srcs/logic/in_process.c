/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:13:46 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/13 18:15:55 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

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

static	void	exec(char **argv, char **envp, int pipe_fds[2])
{
	char	*command_path;
	char	*command;
	char	**arguments;

	command_path = NULL;
	command = NULL;
	arguments = NULL;
	if (close(pipe_fds[0]) == -1)
	{
		perror("close");
		exit(EXIT_FAILURE);
	}
	if (dup2(pipe_fds[1], STDOUT_FILENO) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	close(pipe_fds[1]);
	command = get_command(argv[2]);
	command_path = get_command_path(envp, command);
	free(command);
	arguments = get_com_args(argv[2]);
	exec_command(command_path, arguments, envp);
}

void	in_process(char **argv, char **envp, int pipe_fds[2])
{
	char	*file_name;

	file_name = argv[1];
	dup_file_descriptor(file_name);
	exec(argv, envp, pipe_fds);
}
