/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 21:48:14 by yumamur           #+#    #+#             */
/*   Updated: 2022/12/17 01:57:59 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	arr[11];
	char	d;
	char	sign;

	d = 0;
	if (!n)
		return (ft_putstr_fd("0", fd));
	if (n < 0)
		sign = -1;
	else
		sign = 0;
	while (n)
	{
		arr[11 - d] = 48 + n % 10;
		n %= 10;
		++d;
	}
	if (sign)
		arr[11 - d] = '-';
	ft_putstr_fd(arr + d, fd);
}
