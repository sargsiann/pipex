/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:43:09 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/12 12:44:05 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void    last_process(int *fds, char **argv, int index, char **envp)
{
    if (close(fds[0]) == -1)
    {
        perror("Error: ");
        exit(1);
    }
    exec_command(argv[index], envp);
    if (close(fds[1]) == -1)
    {
        perror("Error: ");
        exit(1);
    }
    exit(0);
}