/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 23:03:22 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/04 17:06:15 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ifexist(t_c_char c, t_c_char *ctrl)
{
	while (*ctrl)
		if (c == *ctrl++)
			return (1);
	return (0);
}

char	*ft_strtrim(t_c_char *s1, t_c_char *set)
{
	t_ulong	size;
	char	*pt;

	if (!s1)
		return (NULL);
	while (s1 && ft_ifexist(*s1, set) != 0)
		s1++;
	size = ft_strlen(s1);
	pt = (char *)&s1[size - 1];
	if (pt == NULL)
		return (NULL);
	while (*s1 != '\0' && ft_ifexist(*pt, set) != 0)
		pt--;
	size = pt - s1 + 2;
	pt = malloc(size);
	if (!pt)
		return (NULL);
	pt[--size] = '\0';
	while (size-- > 0)
		pt[size] = s1[size];
	pt[0] = s1[0];
	return (pt);
}
