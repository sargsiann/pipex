/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 09:33:24 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/08 15:29:22 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(char const *c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
void	*ft_memmove(void *dst, const void *src, size_t len);
int		ft_strncmp(const char	*s1, const char	*s2, size_t n);
char	*ft_strdup(const char *str);

#endif