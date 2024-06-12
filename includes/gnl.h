/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:46:16 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/12 09:30:34 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 4096
# endif

char	*get_next_line(int fd);
size_t	ft_gstrlen(char *s);
char	*ft_gsubstr(char *s, unsigned int start, size_t len, int f);
char	*ft_gstrjoin(char *s1, char *s2, int f, int f2);
void	*ft_gcalloc(size_t num, size_t size);

#endif