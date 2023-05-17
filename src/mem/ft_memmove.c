/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 23:00:49 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/01 23:00:51 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/memft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*ps;
	unsigned char		*pd;

	if (!dest && !src)
		return (NULL);
	ps = (unsigned char *)src;
	pd = (unsigned char *)dest;
	if (ps < pd)
		while (n--)
			*(pd + n) = *(ps + n);
	else
		ft_memcpy(pd, ps, n);
	return (dest);
}
