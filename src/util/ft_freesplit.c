/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freesplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:34:24 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/02 18:16:43 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freesplit(char *arr[])
{
	char	*pt;

	pt = *arr;
	while (pt)
	{
		free(pt);
		pt++;
	}
	free(arr);
	arr = NULL;
}
