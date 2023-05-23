/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 22:57:17 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/01 22:57:18 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	zerosaver(int n)
{
	while (n != 0)
		return (1 + zerosaver(n / 10));
	return (0);
}

static size_t	digitcount(int n)
{
	if (n == 0)
		return (1);
	else
		return (zerosaver(n));
}

char	*ft_itoa(int n)
{
	char	*pt;
	size_t	d;
	long	x;

	x = n;
	d = digitcount(x);
	if (n < 0)
		d += 1;
	pt = malloc(d + 1);
	if (!pt)
		return (NULL);
	if (n < 0)
		x *= -1;
	pt[d] = '\0';
	while (d > 0)
	{
		d--;
		pt[d] = 48 + (x % 10);
		x /= 10;
	}
	if (n < 0)
		pt[0] = '-';
	return (pt);
}
