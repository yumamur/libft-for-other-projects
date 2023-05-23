/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 23:02:52 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/01 23:02:53 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(t_c_char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

size_t	ft_strlen_max(t_c_char *str, size_t max)
{
	size_t	i;

	i = ft_strlen(str);
	if (i > max)
		return (max);
	else
		return (i);
}
