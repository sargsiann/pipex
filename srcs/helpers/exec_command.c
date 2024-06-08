/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:51:28 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/08 18:57:01 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void	exec_command(char	*str, char **envp)
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
}
