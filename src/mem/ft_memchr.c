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

#include "memft.h"

void	*ft_memchr(t_c_void *mem, int c, size_t n)
{
	t_uchar	*ptr;
	size_t	i;

	i = 0;
	ptr = (t_uchar *)mem;
	while (i < n)
	{
		if ((t_uchar) c == ptr[i])
			return (&(void *)ptr[i]);
		i++;
	}
	return (NULL);
}
