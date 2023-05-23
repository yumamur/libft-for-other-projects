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

#include "libft.h"

char	*ft_strnstr(t_c_char *haystack, t_c_char *needle, size_t len)
{
	size_t	n;
	size_t	i;
	size_t	l;

	i = 0;
	if (!haystack && len == 0)
		return (NULL);
	if (!needle[i])
		return ((char *)haystack);
	l = len;
	while (haystack[i] && l-- > 0)
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

int	ft_strnstr_pt(t_c_char *buf, t_c_char *str, size_t len, t_c_char **pt)
{
	*pt = ft_strnstr(buf, str, len);
	if (!*pt)
		return (0);
	return (1);
}

char	*ft_strstr(t_c_char *haystack, t_c_char *needle)
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

int	ft_strstr_pt(t_c_char *buf, t_c_char *str, t_c_char **pt)
{
	*pt = ft_strstr(buf, str);
	if (!pt)
		return (0);
	return (1);
}
