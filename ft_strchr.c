/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:50:08 by yumamur           #+#    #+#             */
/*   Updated: 2022/12/25 00:00:12 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
