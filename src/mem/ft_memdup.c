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

#include "../../include/libft.h"

void	*ft_memdup(const void *mem, size_t n)
{
	void	*ret;

	if (!mem || !n)
		return (NULL);
	ret = malloc(n);
	ft_memcpy(ret, mem, n);
	return (ret);
}
