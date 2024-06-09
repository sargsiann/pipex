/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:46:16 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/09 22:02:31 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# define OPEN_MAX 4096

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
size_t	ft_gstrlen(char *s);
char	*ft_gsubstr(char *s, unsigned int start, size_t len, int f);
char	*ft_gstrjoin(char *s1, char *s2, int f, int f2);
void	*ft_gcalloc(size_t num, size_t size);

#endif