/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 23:02:55 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/01 23:02:56 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(t_c_char *s, char (*f)(t_uint, char))
{
	char	*pt;
	t_uint	i;

	if (!s || (!s && !f))
		return (NULL);
	else if (!f)
		return (ft_strdup(s));
	i = 0;
	pt = malloc(ft_strlen(s) + 1);
	if (!pt)
		return (NULL);
	while (s[i] != '\0')
	{
		pt[i] = (*f)(i, s[i]);
		i++;
	}
	pt[i] = '\0';
	return (pt);
}
