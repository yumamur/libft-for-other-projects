/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:37:42 by yumamur           #+#    #+#             */
/*   Updated: 2023/06/20 17:37:43 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/stackft.h"
#include <stdio.h>

int	ft_stack_swap(t_stack *stack, t_uint i1, t_uint i2)
{
	char	tmp[MAX_TYPE_SIZE];

	if (i1 == i2 || ft_stack_valid(stack, 1) || i1 > stack->size
		|| i2 > stack->size)
		return (-1);
	ft_memcpy(tmp, &stack->data[i1 * stack->_type], stack->_type);
	ft_memcpy(&stack->data[i1 * stack->_type],
		&stack->data[i2 * stack->_type], stack->_type);
	ft_memcpy(&stack->data[i2 * stack->_type], tmp, stack->_type);
	return (0);
}
