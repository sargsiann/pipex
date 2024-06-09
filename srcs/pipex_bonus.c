/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:14:41 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/10 00:39:06 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"


int	main(int argc, char **argv, char **envp)
{
	int		pid;
	int		i;
	char	*data;
	int		fds[2];

	i = 0;
	data = NULL;
	pid = 0;
	if (argc < 5)
	{
		write(2, "Error: Not enough arguments\n", 28);
		return (1);
	}
	while (argv[i + 1] != NULL)
	{
		if (pipe(fds) == -1)
		{
			perror("pipe");
			return (1);
		}
		if (i == 1)
			get_initial_data(argv, argc, fds);
		else
			get_data_from_child();
		give_data_to_child_exec();
	}	
}
