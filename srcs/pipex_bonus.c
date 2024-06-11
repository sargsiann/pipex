/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:14:41 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/11 14:02:12 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"


int	main(int argc, char **argv, char **envp)
{
	int		pid;
	int		pid2;
	int		i;
	int		fds[2];

	i = 2;
	pid = 0;
	pid2 = 0;
	if (argc < 5)
	{
		write(2, "Error: Not enough arguments\n", 28);
		return (1);
	}
	while (argv[i + 1] != NULL)
	{
		fork_logic(fds, argv, i, envp);
		i++;
	}
}
