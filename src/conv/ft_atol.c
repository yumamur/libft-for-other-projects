/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 21:18:20 by yumamur           #+#    #+#             */
/*   Updated: 2023/06/14 21:18:24 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "def/typeft.h"

long	ft_atol(t_c_char *str)
{
	long	ret;
	char	sign;

	sign = 1;
	ret = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign *= -1;
	while (*str >= '0' && *str <= '9')
	{
		ret = (*str - 48) + (ret * 10);
		str++;
	}
	return (ret * sign);
}

long	ft_atol_no_ws(t_c_char *str)
{
	long	ret;
	char	sign;

	sign = 1;
	ret = 0;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign *= -1;
	while (*str >= '0' && *str <= '9')
	{
		ret = (*str - 48) + (ret * 10);
		str++;
	}
	return (ret * sign);
}
