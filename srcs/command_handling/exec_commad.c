/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_commad.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:38:58 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/26 02:47:26 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

static void	free_arguments(char **arguments)
{
	int	i;

	i = 0;
	while (arguments[i])
	{
		free(arguments[i]);
		i++;
	}
	free(arguments);
}

void	exec_command(char *command_path, char **args, char **envp)
{
	printf("akddajdkadd");
	if (execve(command_path, args, envp) == -1)
	{
		perror("Error");
		free_arguments(args);
		free(command_path);
		exit(EXIT_FAILURE);
	}
}
