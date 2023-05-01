/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:13:13 by yumamur           #+#    #+#             */
/*   Updated: 2023/04/30 23:51:59 by yusuf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *mem, int c, size_t n)
{
	unsigned char	*pt;
	size_t			i;

	i = 0;
	pt = (unsigned char *)mem;
	while (i < n)
	{
		if ((unsigned char) c == pt[i])
			return ((void *)mem + i);
		i++;
	}
	return (NULL);
}
