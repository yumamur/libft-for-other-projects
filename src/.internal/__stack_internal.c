/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:22:35 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/14 15:23:27 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/stack_utils.h"

void	_update_index(t_stack *pt_stack)
{
	t_ulint	*pt;

	pt = (t_ulint *)&pt_stack->index;
	if (!pt_stack->size)
		*pt = 0;
	else
		*pt = pt_stack->_type * (pt_stack->size - 1);
}

void	_stack_delone(t_stack *pt_stack)
{
	t_ulint	datasize;
	char	*pt;

	datasize = pt_stack->_type;
	pt = (char *)&(pt_stack->data[pt_stack->index]);
	while (datasize)
		pt[--datasize] = 0;
	_stack_setsize(pt_stack, pt_stack->size - 1);
}

void	_stack_settype(t_stack *pt_stack, t_ulong _type)
{
	t_ulong	*pt;

	pt = (t_ulong *)&pt_stack->_type;
	*pt = _type;
}

void	_stack_setcap(t_stack *pt_stack, t_uint cap)
{
	t_uint	*pt;

	pt = (t_uint *)&pt_stack->cap;
	*pt = cap;
}

void	_stack_setsize(t_stack *pt_stack, t_uint size)
{
	t_uint	*pt;

	pt = (t_uint *)&pt_stack->size;
	*pt = size;
	_update_index(pt_stack);
}
