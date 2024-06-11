/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:51:28 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/11 14:28:15 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void	exec_command(char	*str, char **envp, int fds[2])
{
	char	*command;
	char	**args;

	command = get_command_path(envp, get_command(str));
	args = get_com_args(str);
	if (execve(command, args, envp) == -1)
	{
		perror("Error");
		free(command);
		free(args);
		exit(1);
	}
	free(command);
	free(args);
	close(fds[1]);
	exit(0);
}
