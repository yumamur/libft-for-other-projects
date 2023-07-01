/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:46:44 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/14 15:47:33 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stackft.h"
#include "internal/stack_utils.h"

int	ft_stack_clear(t_stack *stack)
{
	if (ft_stack_valid(stack, 1))
		return (-1);
	while (stack->size)
		_stack_delone(stack);
	return (0);
}
