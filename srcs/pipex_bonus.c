/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:14:41 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/11 14:47:36 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"


int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		fds[2];
	char	*data;

	i = 2;
	data = NULL;
	if (argc < 5)
	{
		write(2, "Error: Not enough arguments\n", 28);
		return (1);
	}
	while (argv[i + 1] != NULL)
	{
		logic(fds, argv, i, envp);
		if (argv[i + 2] == NULL)
		{
			close(fds[1]);
			break ;
		}
		i++;
	}
}
