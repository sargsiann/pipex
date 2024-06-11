/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_initial_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:32:00 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/11 14:21:11 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

static void	get_from_here_doc(char	**argv, int fds[2])
{
	char	*tmp;

	tmp = NULL;
	while (1)
	{
		tmp = get_next_line(0);
		if (ft_strncmp(argv[2], tmp, ft_gstrlen(tmp) - 1) == 0)
		{
			free(tmp);
		}
		write(fds[1], tmp, sizeof(tmp));
		free(tmp);
	}
}

void	get_initial_data(char	**argv, int argc, int fds[2])
{
	int		fd;

	fd = 0;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		if (argc < 6)
		{
			write(2, "Error: Not enough arguments\n", 28);
			exit(1);
		}
		get_from_here_doc(argv, fds);
	}
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			perror("open");
			exit(1);
		}
		dup2(fd, fds[1]);
	}
}
