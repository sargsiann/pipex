/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:07:23 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/12 12:34:55 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void    child1(int *fds, char **argv, int index, char **envp)
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
    exec_command(argv[index], envp);
    if (close(fds[1]) == -1)
    {
        perror("Error: ");
        exit(1);
    }
    exit(0);
}