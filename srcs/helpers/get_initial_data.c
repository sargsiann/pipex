/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_initial_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:32:00 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/07 19:48:25 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

static char	*get_from_file(char **argv, int fd)
{
	char	*data;
	char	*tmp;

	data = NULL;
	tmp = NULL;
	tmp = get_next_line(fd);
	while (tmp)
		data = ft_gstrjoin(data, tmp, 1, 1);
	return (data);
}

static char	*get_from_here_doc(char	**argv)
{
	char	*data;
	char	*tmp;

	data = NULL;
	tmp = NULL;
	while (1)
	{
		tmp = get_next_line(0);
		if (ft_strncmp(tmp, argv[2], ft_strlen(argv[2])) == 0)
			break ;
		data = ft_gstrjoin(data, tmp, 1, 1);
	}
	return (data);
}

char	*get_initial_data(char	**argv)
{
	int		fd;
	char	*data;

	fd = 0;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
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
		data = get_from_file(argv, fd);
	}
	return (data);
}
