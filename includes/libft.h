/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:46:41 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/12 12:41:49 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

char		**ft_split(const char *s, char c, int flag);
size_t		ft_strlen(const char *c);
char		*ft_substr(char *c, unsigned int start,size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
void        *ft_memmove(void *dst, const void *src, size_t len);
char		*ft_strdup(const char *s);
int         ft_strncmp(const char *s1, const char *s2, size_t n);


#endif