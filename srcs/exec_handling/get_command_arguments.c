/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command_arguments.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:07:53 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/12 12:42:22 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

char    **get_comm_args(char *str)
{
    char    **args;
 
    args = ft_split(str, ' ', 0);
    if (args == NULL)
    {
        write(2, "Error: Split error\n", 19);
        exit(1);
    }
    return (args);
}