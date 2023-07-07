/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:47:08 by yumamur           #+#    #+#             */
/*   Updated: 2023/07/07 18:45:42 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stackft.h"

int	ft_stack_init(t_stack *stack, t_uint cap, t_ulong _type)
{
	if (!stack || !cap || !_type)
	{
		if (stack->u_data.c)
			free(stack->u_data.v);
		else
			stack->u_data.v = NULL;
		return (-1);
	}
	_call_internal(ST_SETTYPE, stack, _type);
	_call_internal(ST_SETCAP, stack, cap);
	_call_internal(ST_SETSIZE, stack, 0);
	stack->u_data.v = malloc(cap * stack->_type);
	if (!stack->u_data.v)
		return (-1);
	ft_bzero((void *)stack->u_data.v, cap * stack->_type);
	return (0);
}
