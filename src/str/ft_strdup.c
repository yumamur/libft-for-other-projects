/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 23:02:17 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/12 14:26:04 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcdup(t_c_char *s, int c)
{
	char	*pt;

	pt = ft_strchr(s, c);
	if (!pt)
		return (NULL);
	return (ft_strndup(s, pt - s));
}

char	*ft_strndup(t_c_char *s, t_ulong n)
{
	char	*ret;
	t_ulong	len;
	t_ulong	i;

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

char	*ft_strdup(t_c_char *s)
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
