/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:44:07 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/25 23:35:34 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_strdup(char const *str);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(char const *c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c, int flag);
int     ft_strcmp(char *s1, char *s2);


#endif