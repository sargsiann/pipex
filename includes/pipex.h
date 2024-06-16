/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:40:27 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/16 15:00:56 by dasargsy         ###   ########.fr       */
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

char	*get_command_path(char **envp, char *command);
char	*get_command(char	*str);
char	**get_com_args(char	*command);
void	exec_command(char *command_path, char **args, char **envp);
void	in_process(char **argv, char **envp, int pipe_fds[2]);
void	logic(char **argv, char **envp, int argc);
void	out_process(char **argv, char **envp, int pipe_fds[2], int argc);
void	middle_proccesses(int i, int argc, char **argv, char **envp);

#endif