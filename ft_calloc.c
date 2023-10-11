/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:57:07 by yumamur           #+#    #+#             */
/*   Updated: 2022/12/16 18:40:58 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void		*pt;
	size_t		i;

	pt = malloc(count * size);
	if (!pt)
		return (NULL);
	i = 0;
	while (i < count * size)
		*((unsigned char *)pt + i++) = 0;
	return (pt);
}
