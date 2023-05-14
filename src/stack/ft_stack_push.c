/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:47:27 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/14 15:47:28 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/stackft.h"
#include "../../include/def/stackft_internal.h"

void	ft_stack_push(t_stack *pt_stack, void *val)
{
	if (!pt_stack)
	{
		write(2, "\nNo stack initialized\n", 22);
		return ;
	}
	if (pt_stack->size == pt_stack->cap)
	{
		write(2, "\nStack is full, consider ft_stack_xpanda.\n", 42);
		ft_stack_xpanda(pt_stack, 1);
	}
	_stack_setsize(pt_stack, pt_stack->size + 1);
	ft_memcpy((void *)&(pt_stack->data[pt_stack->index]), val, pt_stack->_type);
}
