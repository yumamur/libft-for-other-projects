/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 23:02:08 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/01 23:02:09 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			index;
	unsigned char	*pt;

	index = 0;
	pt = (unsigned char *)s;
	while (pt[index] != '\0')
	{
		if ((char) c == pt[index])
			return ((char *)pt + index);
		index++;
	}
	if ((char) c == '\0')
		return ((char *)pt + index);
	return (NULL);
}

char	*ft_strrchr(const char *s, int c)
{
	size_t	index;

	index = ft_strlen(s);
	if ((char) c == '\0')
		return ((char *) s + index);
	while (index-- > 0)
		if (s[index] == (char) c)
			return ((char *) s + index);
	if (s[0] == (char) c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strnchr(const char *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*pt;

	index = 0;
	pt = (unsigned char *)s;
	while (pt[index] != '\0' && index < n)
	{
		if ((char) c == pt[index])
			return ((char *)pt + index);
		index++;
	}
	if ((char) c == '\0')
		return ((char *)pt + index);
	return (NULL);
}
