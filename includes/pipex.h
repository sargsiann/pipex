/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 09:33:52 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/10 00:35:52 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H
# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include "gnl.h"
void    get_initial_data(char	**argv, int argc, int fds[2]);
char	*get_command_path(char **envp, char *command);
char	**get_com_args(char	*str);
void	put_to_file(char **argv, char	*data, char *filename);
void	exec_command(char	*str, char **envp);
char	*get_command(char	*str);
int     create_and_exec_child(char **argv, char **envp, int index, int fds[2]);



#endif