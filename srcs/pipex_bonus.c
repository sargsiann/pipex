/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:39:57 by dasargsy          #+#    #+#             */
/*   Updated: 2024/07/05 17:04:32 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	get_command_count(char **cmds)
{
	int	i;

	i = 0;
	while (cmds[i])
		i++;
	return (i - 1);
}

int	get_status(int pid)
{
	int	status;

	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (status);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc < 5)
	{
		write(2, "error", 5);
		exit(EXIT_FAILURE);
	}
	if (ft_strcmp(argv[1], "here_doc") == 0)
		handle_here_doc(argc, argv, envp);
	else
	{
		// fprintf(stderr, "error: %s\n", ARG_ERR);
		handle_input_file(argc, argv, envp);
	}
	return (0);
}
