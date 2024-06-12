/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 09:32:09 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/12 12:35:52 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include <string.h>

# include "libft.h"
# include "gnl.h"

void	exec_command(char *str, char **envp);
char	*get_command_path(char **envp, char *command);
char	*get_command(char *str);
char	**get_comm_args(char *str);
void    end_data_to_file(char *file, char **argv);
void    init_data_to_pipe(int argc, char **argv);
void    logic(char **argv, char **envp, int i);
void    child1(int *fds, char **argv, int index, char **envp);
void    child2(int *fds, char **argv, int index, char **envp);

# endif