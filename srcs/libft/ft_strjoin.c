/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:48:30 by dasargsy          #+#    #+#             */
/*   Updated: 2024/06/12 12:37:57 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	a;
	char	*joined;
	size_t	len1;
	size_t	len2;


	joined = NULL;
	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	a = len1+ len2 + 1;
	joined = (char *)malloc(a * sizeof(char));
	if (!joined)
		return (NULL);
	ft_memmove(joined, s1, len1);
	ft_memmove(joined + len1, s2, len2);
	joined[a - 1] = '\0';
	return (joined);
}
