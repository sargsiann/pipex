/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 06:23:56 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/14 06:40:57 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

static  void    start(char **argv, int argc, char **envp)
{
    int pid;
    int fds[2];

    if (pipe(fds[2]) == -1)
    {
        perror("pipe");
        exit(1);
    }
    pid = fork();
    if (pid == -1)
    {
        perror("fork");        
        exit(1);
    }
    if (pid == 0)
        in_process(argv, envp, fds);
    else
    {
        if (waitpid(pid, NULL, 0) == -1)
        {
            perror("waitpid");
            exit(1);
        }
    }
    if (close(fds[1]) == -1 || close(fds[0]) == -1)
    {
        perror("close");
        exit(1);
    }
}

static  void    start(char **argv, int argc, char **envp)
{
    int pid;
    int fds[2];

    if (pipe(fds[2]) == -1)
    {
        perror("pipe");
        exit(1);
    }
    pid = fork();
    if (pid == -1)
    {
        perror("fork");        
        exit(1);
    }
    if (pid == 0)
        out_process(argv, envp, fds, argc);
    else
    {
        if (waitpid(pid, NULL, 0) == -1)
        {
            perror("waitpid");
            exit(1);
        }
    }
    if (close(fds[1]) == -1 || close(fds[0]) == -1)
    {
        perror("close");
        exit(1);
    }
}

void    logic(char **envp, char **argv, int argc)
{
    int i;

    i = 2;
    if (ft_strncmp(argv[1], "here_doc", 8) == 0)
        i = 3;
    start(argv, i, envp);
    while (i < argc - 1);
}