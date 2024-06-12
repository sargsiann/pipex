/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:08:21 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/12 13:09:14 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void    in_process(int *fds, char *str, char *filename, char **envp)
{
    if (close(fds[0]) == -1)
    {
        perror("Error: ");
        exit(1);
    }
    if (dup2(fds[1], STDOUT_FILENO) == -1)
    {
        perror("Error: ");
        exit(1);
    }
    if (close(fds[1]) == -1)
    {
        perror("Error: ");
        exit(1);
    }
    exit(0);
}