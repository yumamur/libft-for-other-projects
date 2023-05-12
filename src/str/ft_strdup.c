/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 23:02:17 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/11 20:09:47 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strcdup(const char *s, int c)
{
	char	*ret;
	int		i;

	ret = ft_strchr(s, c);
	if (!ret)
		return (NULL);
	ret = malloc(ret - s + 1);
	i = -1;
	while (++i < ret - s)
		ret[i] = s[i];
	ret[i] = '\0';
	return (ret);
}

char	*ft_strndup(const char *s, size_t n)
{
	char	*ret;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	if (n > len)
		ret = malloc(len + 1);
	else
	{
		len = n;
		ret = malloc(len + 1);
	}
	if (!ret)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_strdup(const char *s)
{
	char	*ret;
	int		i;

	ret = malloc(ft_strlen(s) + 1);
	if (!ret)
		return (NULL);
	i = -1;
	while (s[++i] != '\0')
		ret[i] = s[i];
	ret[i] = '\0';
	return (ret);
}
