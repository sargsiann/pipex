/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_data_to_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 19:41:21 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/08 16:25:37 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void	put_to_file(char **argv, char	*data, char *filename)
{
	int	fd;

	fd = 0;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		fd = open(filename, O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (fd == -1)
		{
			perror("Error");
			exit(1);
		}
		write(fd, data, ft_strlen(data));
		close(fd);
	}
	else
	{
		fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (fd == -1)
		{
			perror("Error");
			exit(1);
		}
		write(fd, data, ft_strlen(data));
		close(fd);
	}
}
