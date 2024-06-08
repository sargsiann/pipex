/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_initial_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:32:00 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/08 19:35:32 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

static char	*get_from_file(int fd)
{
	char	*data;
	char	*tmp;

	data = ft_strdup("");
	tmp = NULL;
	tmp = get_next_line(fd);
	while (tmp)
	{
		data = ft_gstrjoin(data, tmp, 1, 1);
		tmp = get_next_line(fd);
	}
	return (data);
}

static char	*get_from_here_doc(char	**argv)
{
	char	*data;
	char	*tmp;

	data = ft_strdup("");
	tmp = NULL;
	while (1)
	{
		tmp = get_next_line(0);
		if (ft_strncmp(argv[2], tmp, ft_gstrlen(tmp) - 1) == 0)
		{
			free(tmp);
			return (data);		
		}
		data = ft_gstrjoin(data, tmp, 1, 1);
	}
	return (data);
}

char	*get_initial_data(char	**argv, int argc)
{
	int		fd;
	char	*data;

	fd = 0;
	data = NULL;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		if (argc < 6)
		{
			write(2, "Error: Not enough arguments\n", 28);
			exit(1);
		}
		data = get_from_here_doc(argv);
	}
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			perror("open");
			exit(1);
		}
		data = get_from_file(fd);
		close(fd);
	}
	return (data);
}
