/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:13:13 by yumamur           #+#    #+#             */
/*   Updated: 2023/04/12 19:33:32 by yusuf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*pt;

	i = 0;
	pt = (unsigned char *)s;
	while (i < n)
	{
		if ((unsigned char) c == pt[i])
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
