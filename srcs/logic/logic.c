/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:58:11 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/13 19:13:31 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

static void	wait_for_status(int pid)
{
	int	status;
	int	exit1;

	if (waitpid(pid, &status, 0) == -1)
	{
		perror("waitpid");
		exit(EXIT_FAILURE);
	}
	else if (WIFEXITED(status))
	{
		exit1 = WEXITSTATUS(status);
		if (exit1 == EXIT_FAILURE)
		{
			perror("child wrong");
			exit(EXIT_FAILURE);
		}
	}
}

static void	close_fds(int *fds)
{
	if (close(fds[0]) == -1)
	{
		perror("close");
		exit(EXIT_FAILURE);
	}
	if (close(fds[1]) == -1)
	{
		perror("close");
		exit(EXIT_FAILURE);
	}
}

void	logic(char **argv, char **envp, int argc)
{
	int	pid1;
	int	pid2;
	int	fds[2];

	if (pipe(fds) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	pid1 = fork();
	if (pid1 == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid1 == 0)
		in_process(argv, envp, fds);
	pid2 = fork();
	if (pid2 == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	if (pid2 == 0)
		out_process(argv, envp, fds, argc);
	wait_for_status(pid2);
	close_fds(fds);
}
