/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 18:46:55 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/08 19:03:05 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

static int	find_spc_index(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	return (i);

}

char	*get_command(char	*str)
{
	int		index;
	char	*command;

	index = find_spc_index(str);
	command = ft_substr(str, 0, index);
	command = ft_gstrjoin("/", command, 0, 1);
	return (command);
}
