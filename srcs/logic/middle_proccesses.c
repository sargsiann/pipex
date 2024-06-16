/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_proccesses.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:09:24 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/16 17:16:38 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

static	void	exec(char **argv, char **envp, int pipe_fds[2], int i)
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
	command = get_command(argv[i]);
	command_path = get_command_path(envp, command);
	free(command);
	arguments = get_com_args(argv[i]);
	exec_command(command_path, arguments, envp);
}

void	middle_proccesses(int i, int argc, char **argv, char **envp)
{
	int	pid;
	int	fds[2];

	if (pipe(fds) == -1)
	{
		perror("pipe");
		exit(1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("pipe");
		exit(1);
	}

	if (pid == 0)
		exec(argv, envp, fds, i);
	else
	{
		if (dup2(fds[0], STDIN_FILENO) == -1)
		{
			perror("dup2");
			exit(EXIT_FAILURE);
		}
		close(fds[0]);
		close(fds[1]);
		if (waitpid(pid, NULL, 0) == -1)
		{
			perror("waitpid");
			exit(1);
		}
	}	
}