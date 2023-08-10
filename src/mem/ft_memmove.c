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

void	*ft_memmove(void *dst, t_c_void *src, size_t n)
{
	t_uchar	*ptr_s;
	t_uchar	*ptr_d;

	if (!dst && !src)
		return (NULL);
	ptr_s = (t_uchar *)src;
	ptr_d = (t_uchar *)dest;
	if (ptr_s < ptr_d)
		while (n--)
			*(ptr_d + n) = *(ptr_s + n);
	else
		ft_memcpy(ptr_d, ptr_s, n);
	return (dst);
}
