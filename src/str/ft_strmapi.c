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

#include "../../include/libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*pt;
	unsigned int	i;

	if (!s || (!s && !f))
		return (NULL);
	else if (!f)
		return (ft_strdup(s));
	i = 0;
	pt = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
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
