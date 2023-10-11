/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:30:03 by yumamur           #+#    #+#             */
/*   Updated: 2022/12/24 23:42:11 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char	*ft_itoa(int n)
{
	char	ret[15];

	if (n == 0)
		return (ft_strdup("0"));
	ret[14] = 0;
	*(int *)&ret[10] = n;
	while (*(int *)&ret[10] && ++ret[14])
		*(int *)&ret[10] /= 10;
	*(int *)&ret[10] = n;
	if (n < 0 && ++ret[14])
		*(int *)&ret[10] *= -1;
	*(ret + ret[14]) = '\0';
	while (ret[14]-- > 0)
	{
		*(ret + ret[14]) = 48 + (*(int *)&ret[10] % 10);
		*(int *)&ret[10] /= 10;
	}
	if (n < 0)
		ret[0] = '-';
	return (ft_strdup(ret));
}
