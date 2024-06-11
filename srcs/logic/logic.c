/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:54:57 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/11 14:44:48 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

static int	handle_exit_status(int pid1, int pid2)
{
	int	status;

	waitpid(pid1, &status, 0);
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) != 0)
			return (1);
	}
	waitpid(pid2, &status, 0);
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) != 0)
			return (1);
	}
	return (0);
}

void	logic(int fds[2], char **argv, int index, char **envp)
{
	int		pid1;
	int		pid2;

	pipe(fds);
	pid1 = fork();
	pid2 = 0;
	if (pid1 == -1)
	{
		perror("fork");
		exit(1);		
	}
	else if (pid1 == 0)
		from(argv, index, fds, envp);
	pid2 = fork();
	if (pid2 == -1)
	{
		perror("fork");
		exit(1);
	}
	else if (pid2 == 0)
		to(argv, index, fds, envp);
	if (pid1 > 0 && pid2 > 0)
	{
		close(fds[0]);
		close(fds[1]);
		if (handle_exit_status(pid1, pid2) == 1)
			exit(1);
	}
}
