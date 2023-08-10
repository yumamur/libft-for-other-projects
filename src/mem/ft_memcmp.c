/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 23:00:40 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/01 23:00:42 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memft.h"

int	ft_memcmp(t_c_void *mem1, t_c_void *mem2, size_t n)
{
	t_uchar	*ptr1;
	t_uchar	*ptr2;
	size_t	i;

	i = 0;
	ptr1 = ((t_uchar *)arr1);
	ptr2 = ((t_uchar *)arr2);
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (ptr1[i] != ptr2[i])
			return ((t_uchar)ptr1[i] - (t_uchar)ptr2[i]);
		i++;
	}
	return (0);
}
