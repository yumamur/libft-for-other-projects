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

#include "memft.h"

void	*ft_memmove(void *dest, t_c_void *src, size_t n)
{
	t_uchar	*ps;
	t_uchar	*pd;

	if (!dest && !src)
		return (NULL);
	ps = (t_uchar *)src;
	pd = (t_uchar *)dest;
	if (ps < pd)
		while (n--)
			*(pd + n) = *(ps + n);
	else
		ft_memcpy(pd, ps, n);
	return (dest);
}
