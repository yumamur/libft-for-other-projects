/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 23:02:40 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/01 23:02:42 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(t_c_char *s1, t_c_char *s2)
{
	size_t	l1;
	size_t	l2;
	char	*r;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	r = malloc(l1 + l2 + 1);
	if (!r)
		return (NULL);
	while (*s1 != '\0')
		*(r++) = *((char *)s1++);
	while (*s2 != '\0')
		*(r++) = *((char *)s2++);
	*r = '\0';
	return (r - l1 - l2);
}
