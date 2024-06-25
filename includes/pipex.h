/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:40:27 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/26 00:46:53 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include "gnl.h"
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>

# define WAIT_ERR 			"Waitpid Failed\n"
# define MALLOC_ERR 		"Allocation Failed\n"
# define ARG_ERR			"Invalid number of arguments\n"
# define WRT_PERM_ERR		"No write permission\n"
# define FILE_OPEN_ERR		"Can't open the file\n"
# define PIPE_CLOSE_ERR		"Can't close the pipe\n"
# define PIPE_CREATE_ERR	"Can't create the pipe\n"
# define FORK_CREATE_ERR	"Can't create the child process\n"
# define DUP_ERR			"Can't duplicate the descriptor\n"
# define EXEC_ERR			"Can't execute the command\n"
# define CMD_NOT_FOUND_ERR	"Command not found\n"

# define WAIT_STAT 			2
# define MALLOC_STAT 		3
# define ARG_STAT			4
# define WRT_PERM_STAT		1
# define FILE_OPEN_STAT		6
# define PIPE_CLOSE_STAT	7
# define PIPE_CREATE_STAT	8
# define FORK_CREATE_STAT	9
# define DUP_STAT			10
# define EXEC_STAT			126
# define CMD_NOT_FOUND_STAT	127

char	*get_command_path(char **envp, char *command);
char	*get_command(char	*str);
char	**get_com_args(char	*command);
void	exec_command(char *command_path, char **args, char **envp);
void	logic(char **argv, char **envp, int argc);
void    ft_error(char *message, int exit_status);
void    in_process(char **argv, int i, char **envp);
#endif