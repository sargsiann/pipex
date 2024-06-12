/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:48:40 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/12 12:35:34 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void    wait_get_status(int pid1, int pid2, int fds[2])
{
    int status;

    waitpid(pid1, &status, 0);
    if (WIFEXITED(status))
    {
        if (WEXITSTATUS(status) != 0)
        {
            perror("Error: ");
            exit(1);
        }
    }
    waitpid(pid2, &status, 0);
    if (WIFEXITED(status))
    {
        if (WEXITSTATUS(status) != 0)
        {
            perror("Error: ");
            exit(1);
        }
    }
    if (close(fds[0]) == -1)
    {
        perror("Error: ");
        exit(1);
    }
    if (close(fds[1]) == -1)
    {
        perror("Error: ");
        exit(1);
    }
}

void    logic(char **argv, char **envp, int i)
{
    int fds[2];
    int pid1;
    int pid2;

    if (pipe(fds) == -1)
    {
        perror("Error: ");
        exit(1);
    }
    pid1 = fork();
    if (pid1 == -1)
    {
        perror("Error: ");
        exit(1);
    }
    if (pid1 == 0)
        child1(fds, argv, i, envp);
    pid2 = fork();
    if (pid2 == -1)
    {
        perror("Error: ");
        exit(1);
    }
    if (pid2 == 0)
        child2(fds, argv, i + 1, envp);
    wait_get_status(pid1, pid2, fds);
}