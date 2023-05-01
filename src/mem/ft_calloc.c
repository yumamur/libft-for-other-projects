/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:57:07 by yumamur           #+#    #+#             */
/*   Updated: 2023/04/30 23:38:51 by yusuf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void		*pt;

	pt = malloc(count * size);
	if (!pt)
		return (NULL);
	ft_bzero(pt, (count * size));
	return (pt);
}
