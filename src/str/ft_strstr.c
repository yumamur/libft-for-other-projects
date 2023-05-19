/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:11:51 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/19 19:11:52 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n;
	size_t	i;
	size_t	l;

	i = 0;
	if (haystack == NULL && len == 0)
		return (0);
	if (needle[i] == '\0')
		return ((char *)haystack);
	l = len;
	while (haystack[i] != '\0' && l-- > 0)
	{
		n = 0;
		while (haystack[i + n] == needle[n] && haystack[i + n] != '\0')
		{
			if (needle[n + 1] == '\0' && len > n + i)
				return ((char *)&haystack[i]);
			n++;
		}
		i++;
	}
	return (NULL);
}

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	n;
	size_t	i;

	i = 0;
	if (haystack == NULL)
		return (0);
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		n = 0;
		while (haystack[i + n] == needle[n] && haystack[i + n] != '\0')
		{
			if (needle[n + 1] == '\0')
				return ((char *)&haystack[i]);
			n++;
		}
		i++;
	}
	return (NULL);
}
