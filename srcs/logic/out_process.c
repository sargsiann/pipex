/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:53:07 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/13 18:44:43 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

static	void	dup2_to_file(char	*filename)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	close(fd);
}

static	void	exec(char **argv, char **envp, int pipe_fds[2], int argc)
{
	char	*command_path;
	char	*command;
	char	**arguments;

	command_path = NULL;
	command = NULL;
	arguments = NULL;
	if (close(pipe_fds[1]) == -1)
	{
		perror("close");
		exit(EXIT_FAILURE);
	}
	if (dup2(pipe_fds[0], STDIN_FILENO) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	if (close(pipe_fds[0]) == -1)
	{
		perror("close");
		exit(EXIT_FAILURE);
	}
	command = get_command(argv[argc - 2]);
	command_path = get_command_path(envp, command);
	free(command);
	arguments = get_com_args(argv[argc - 2]);
	exec_command(command_path, arguments, envp);
}

void	out_process(char **argv, char **envp, int pipe_fds[2], int argc)
{
	char	*filename;

	filename = argv[argc - 1];
	dup2_to_file(filename);
	exec(argv, envp, pipe_fds, argc);
}