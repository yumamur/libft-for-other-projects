/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 23:00:54 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/01 23:00:56 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memft.h"

void	*ft_memset(void *mem, int set, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((t_uchar *)mem)[i] = set;
		i++;
	}
	return (mem);
}
