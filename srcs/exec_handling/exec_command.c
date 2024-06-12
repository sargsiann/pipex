/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:06:31 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/12 10:10:47 by dasargsy         ###   ########.fr       */
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