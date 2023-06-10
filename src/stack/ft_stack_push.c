/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:47:27 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/19 16:01:25 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stackft.h"
#include "internal/stack_utils.h"

void	ft_stack_push(t_stack *pt_stack, void *val)
{
	static char	ctl;

	if (!pt_stack)
	{
		write(2, "\nNo stack initialized\n", 22);
		return ;
	}
	if (!ctl)
		ctl = 0;
	if (pt_stack->size == pt_stack->cap)
	{
		ctl++;
		write(2, "\nStack is full, consider ft_stack_xpanda.\n", 42);
		if (ctl < 3)
			ft_stack_xpanda(pt_stack, 1);
		else
		{
			write(2, "\nIncrease cap reached. Check your code.\n", 40);
			return ;
		}
	}
	_stack_setsize(pt_stack, pt_stack->size + 1);
	ft_memcpy((char *)&((pt_stack->data)[pt_stack->index]),
		val, pt_stack->_type);
}
