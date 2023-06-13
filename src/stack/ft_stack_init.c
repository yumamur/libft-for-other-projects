/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:47:08 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/14 15:47:13 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stackft.h"
#include "internal/stack_utils.h"

void	ft_stack_init(t_stack *stack, t_uint cap, t_ulong _type)
{
	if (!stack || !cap || !_type)
	{
		if (stack->data)
			free((void *)stack->data);
		else
			stack->data = NULL;
		return ;
	}
	_stack_settype(stack, _type);
	_stack_setcap(stack, cap);
	_stack_setsize(stack, 0);
	stack->data = malloc(cap * stack->_type);
	ft_bzero((void *)stack->data, cap * stack->_type);
}
