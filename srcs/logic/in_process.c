/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 00:20:03 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/26 03:13:09 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

static void get_from_here_doc(int fds[2], char *limiter)
{
    char    *tmp;

    while (1)
    {
        tmp = get_next_line(0);
        if (ft_strncmp(tmp, limiter, ft_strlen(tmp) - 1) == 0)
        {
            free(tmp);
            break;
        }
        write(fds[1], tmp, ft_strlen(tmp) - 1);
        free(tmp);
    }
}

static void dup_file(int fds[2], char **argv)
{
    int      fd;
    char    *filename;

    
    filename = argv[1];
    fd = 0;
    if (access(filename, F_OK) == -1)
        ft_error(DUP_ERR, DUP_STAT);
    fd = open(filename, O_RDONLY);
    if (fd == -1)
        ft_error(FILE_OPEN_ERR, FILE_OPEN_STAT);
    if (dup2(fds[1], fd) == -1)
        ft_error(DUP_ERR, DUP_STAT);
    close(fd);
}

static void dup_initial(int fds[2], char **argv)
{
    if (ft_strncmp(argv[1],"here_doc",8) == 0)
        get_from_here_doc(fds, argv[2]);
    else
        dup_file(fds, argv);
}

static void exec(int fds[2], char **argv, int i, char **envp)
{
    char    *command;
    char    *path;
    char    **args;

    command = get_command(argv[i]);
    path = get_command_path(envp, command);
    args = get_com_args(command);
    free(command);
    exec_command(path, args, envp);
}

void    in_process(char **argv, int i, char **envp)
{
    int fds[2];
    int pid;

    if (pipe(fds) == -1)
        ft_error(PIPE_CREATE_ERR, PIPE_CREATE_STAT);
    pid = fork();
    if (pid == -1)
        ft_error(FORK_CREATE_ERR, FORK_CREATE_STAT);
    if (pid)
    {
        close(fds[1]);
        dup2(fds[0],STDIN_FILENO);
        close(fds[0]);
        waitpid(pid, NULL, 0);
    }
    else if (pid == 0)
    {
        if (i == 2)
            dup_initial(fds, argv);
        else
        {
            if (close(fds[0]) == -1)
			    ft_error(PIPE_CLOSE_ERR, PIPE_CLOSE_STAT);
		    if (dup2(fds[1], STDOUT_FILENO) == -1)
			    ft_error(DUP_ERR, DUP_STAT);
		    if (close(fds[1]) == -1)
			    ft_error(PIPE_CLOSE_ERR, PIPE_CLOSE_STAT);
            exec(fds, argv, i, envp);
        }
    }
}