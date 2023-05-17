/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 23:00:32 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/01 23:00:33 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/memft.h"

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
