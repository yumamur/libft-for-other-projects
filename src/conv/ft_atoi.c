/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 22:57:00 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/01 22:57:01 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "def/typeft.h"

int	ft_atoi(t_c_char *str)
{
	int		ret;
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

int	ft_atoi_no_ws(t_c_char *str)
{
	int		ret;
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
