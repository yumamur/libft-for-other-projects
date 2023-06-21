/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 23:01:27 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/01 23:01:29 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int fd, int n)
{
	char	c;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			n *= -1;
			write(fd, "-", 1);
		}
		if (n <= 9)
		{
			c = n + 48;
			write(fd, &c, 1);
		}
		else
		{
			ft_putnbr_fd(fd, (n / 10));
			ft_putnbr_fd(fd, (n % 10));
		}
	}
}
