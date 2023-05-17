/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 23:00:45 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/01 23:00:46 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/memft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*ps;
	unsigned char		*pd;

	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest == src)
		return (dest);
	ps = (const unsigned char *)src;
	pd = (unsigned char *)dest;
	i = 0;
	while (n--)
	{
		pd[i] = ps[i];
		i++;
	}
	return (dest);
}

void	*ft_memcpy_rev(void *dest, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*ps;
	unsigned char		*pd;

	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest == src)
		return (dest);
	ps = (const unsigned char *)src;
	pd = (unsigned char *)dest;
	i = 0;
	while (n--)
	{
		pd[n] = ps[i];
		i++;
	}
	return (dest);
}
