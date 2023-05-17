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

#include "../../include/def/stackft_internal.h"

void	_update_index(t_stack *pt_stack)
{
	unsigned long int	*pt;

	pt = (unsigned long int *)&pt_stack->index;
	if (!pt_stack->size)
		*pt = 0;
	else
		*pt = pt_stack->_type * (pt_stack->size - 1);
}

void	_stack_delone(t_stack *pt_stack)
{
	unsigned long int	datasize;
	char				*pt;

	datasize = pt_stack->_type;
	pt = (char *)&(pt_stack->data[pt_stack->index]);
	while (datasize)
		pt[--datasize] = 0;
	_stack_setsize(pt_stack, pt_stack->size - 1);
}

void	_stack_settype(t_stack *pt_stack, unsigned long _type)
{
	unsigned long	*pt;

	pt = (unsigned long *)&pt_stack->_type;
	*pt = _type;
}

void	_stack_setcap(t_stack *pt_stack, unsigned int cap)
{
	unsigned int	*pt;

	pt = (unsigned int *)&pt_stack->cap;
	*pt = cap;
}

void	_stack_setsize(t_stack *pt_stack, unsigned int size)
{
	unsigned int	*pt;

	pt = (unsigned int *)&pt_stack->size;
	*pt = size;
	_update_index(pt_stack);
}
