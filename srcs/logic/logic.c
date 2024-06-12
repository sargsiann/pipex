/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:48:40 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/12 11:19:37 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void    logic(char **argv, char **envp, int i)
{
    int		fd[2];
    int		pid;
    int		status;

    if (pipe(fd) == -1)
    {
        perror("Error");
        exit(1);
    }
    pid = fork();
    if (pid == -1)
    {
        perror("Error");
        exit(1);
    }
    if (pid == 0)
    {
        dup2(fd[1], 1);
        close(fd[0]);
        close(fd[1]);
        exec_command(argv[i], envp);
    }
    else
    {
        waitpid(pid, &status, 0);
        pid = fork();
        if (pid == -1)
        {
            perror("Error");
            exit(1);
        }
        if (pid == 0)
        {
            dup2(fd[0], 0);
            close(fd[0]);
            close(fd[1]);
            exec_command(argv[i], envp);
        }
        else
        {
            waitpid(pid, &status, 0);
            close(fd[0]);
            close(fd[1]);
        }
    }
}