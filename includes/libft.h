/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:46:41 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/12 10:11:17 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

char		**ft_split(const char *s, char c);
size_t		ft_strlen(const char *c);
char		*ft_substr(char *c, unsigned int start,size_t len);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(const char *s);
char        *ft_strncmp(const char *s1, const char *s2, size_t n);


#endif