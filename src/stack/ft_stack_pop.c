/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:51:20 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/14 15:51:21 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stackft.h"
#include "def/stackft_internal.h"

void	*ft_stack_pop(t_stack *pt_stack)
{
	void	*pt;

	if (!pt_stack || !pt_stack->data || !pt_stack->size)
	{
		write(2, "\nNo data to pop\n", 16);
		return (NULL);
	}
	pt = ft_memdup(&(pt_stack->data[pt_stack->index]), pt_stack->_type);
	_stack_delone(pt_stack);
	return (pt);
}
