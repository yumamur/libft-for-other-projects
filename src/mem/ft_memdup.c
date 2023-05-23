/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:57:22 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/14 15:57:23 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memft.h"

void	*ft_memdup(t_c_void *mem, size_t n)
{
	void	*ret;

	if (!mem || !n)
		return (NULL);
	ret = malloc(n);
	ft_memcpy(ret, mem, n);
	return (ret);
}

void	*ft_memdup_rev(t_c_void *mem, size_t n)
{
	void	*ret;

	if (!mem || !n)
		return (NULL);
	ret = malloc(n);
	ft_memcpy_rev(ret, mem, n);
	return (ret);
}
