/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 23:02:01 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/08 17:34:55 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_arrcount(t_c_char *str, char c)
{
	size_t	count;

	count = 0;
	while (*str != '\0')
	{
		if (*str == c)
			str++;
		else
		{
			count++;
			while (*str != c && *str != '\0')
				str++;
		}
	}
	return (count);
}

static size_t	ft_wordlen(t_c_char *str, char c)
{
	size_t	i;

	i = 0;
	while (*str != '\0')
	{
		if (*str == c && *(str - 1) != c)
			break ;
		if (*str != c)
			i++;
		str++;
	}
	return (i);
}

static char	**ft_splinter(t_c_char *str, char c, char **pt, size_t count)
{
	size_t	n;

	n = 0;
	if (count != 0)
	{
		while (*str != '\0')
		{
			count = 0;
			pt[n] = malloc(ft_wordlen(str, c) + 1);
			if (!pt[n])
				return (NULL);
			while (*str != c && *str != '\0')
				pt[n][count++] = *(str++);
			if (*str == '\0')
				str--;
			pt[n][count] = '\0';
			str++;
			while (*str == c && *str != '\0')
				str++;
			n++;
		}
	}
	pt[n] = NULL;
	return (pt);
}

char	**ft_split(t_c_char *str, char c)
{
	size_t	count;
	char	**pt;

	if (!str || str[0] == 0)
	{
		pt = ft_calloc(1, 1);
		if (!pt)
			return (NULL);
		pt[0] = NULL;
		return (pt);
	}
	while (*str == c)
		str++;
	count = ft_arrcount(str, c);
	pt = malloc((count + 1) * 8);
	if (!pt)
		return (NULL);
	ft_splinter(str, c, pt, count);
	return (pt);
}
