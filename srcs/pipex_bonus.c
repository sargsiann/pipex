/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:14:41 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/10 01:05:48 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"


int	main(int argc, char **argv, char **envp)
{
	int		pid;
	int		i;
	int		call[2];
	int		callback[2];

	i = 0;
	pid = 0;
	if (argc < 5)
	{
		write(2, "Error: Not enough arguments\n", 28);
		return (1);
	}
	while (argv[i + 1] != NULL)
	{
		if (pipe(call) == -1)
		{
			perror("pipe");
			return (1);
		}
		pid = fork();
		if (i == 1)
			get_initial_data(argv, argc, call);
		else
			get_data_from_child(callback);
		if (pid == -1)
		{
			perror("fork");
			return (1);
		}
		give_data_to_child_exec(pid);
	}
}
