/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_final_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:02:18 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/11 14:21:08 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

char	*get_final_data(int fd)
{
	char	*data;
	char	*tmp;

	data = ft_strdup("");
	tmp = NULL;
	while (1)
	{
		tmp = get_next_line(0);
		if (!tmp)
			break ;
		data = ft_gstrjoin(data, tmp, 1, 1);
	}
	return (data);
}
