/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_2pt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:46:21 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/20 16:46:22 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_realloc_2pt(void **arr, size_t n)
{
	void	**ret;
	t_ulong	i;

	if (!arr)
		return (NULL);
	i = 0;
	while (arr[i])
		i++;
	if (i >= n)
		return (arr);
	ret = malloc(i * 8);
	i = -1;
	while (arr[++i])
		ret[i] = arr[i];
	return (ret);
}
