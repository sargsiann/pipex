/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 06:23:56 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/16 15:57:56 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

static	void	get_status(int pid)
{
	int	status;
	
	if (waitpid(pid, &status, 0) == -1)
	{
		perror("waitpid");
		exit(EXIT_FAILURE);
	}
	if (WIFEXITED(status))
		exit(WEXITSTATUS(status));
}

static  void    start(char **argv, int argc, char **envp)
{
    int pid;
    int fds[2];

    if (pipe(fds) == -1)
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
		if (close(fds[1]) == -1 || close(fds[0]) == -1)
   		{
        	perror("close");
        	exit(1);
    	}
        if (waitpid(pid, NULL, 0) == -1)
        {
            perror("waitpid");
            exit(1);
        }
    }
}

static  void    end(char **argv, int argc, char **envp)
{
    int pid;
    int fds[2];

    if (pipe(fds) == -1)
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
		if (close(fds[1]) == -1 || close(fds[0]) == -1)
    	{
       		perror("close");
        	exit(1);
    	}
		get_status(pid);
    }
}

void    logic(char **argv, char **envp, int argc)
{
    int i;

    i = 2;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
        i = 3;
	start(argv, argc, envp);
	while (i < argc - 2)
	{
		middle_proccesses(i, argc, argv, envp);
		i++;
	}
	end(argv, argc, envp);
}