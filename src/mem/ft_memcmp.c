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

int	ft_memcmp(t_c_void *s1, t_c_void *s2, size_t n)
{
	t_uchar	*ss1;
	t_uchar	*ss2;
	size_t	i;

	i = 0;
	ss1 = ((t_uchar *)s1);
	ss2 = ((t_uchar *)s2);
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (ss1[i] != ss2[i])
			return ((t_uchar)ss1[i] - (t_uchar)ss2[i]);
		i++;
	}
	return (0);
}
