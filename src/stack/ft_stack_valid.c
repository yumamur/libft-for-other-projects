/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:29:23 by yumamur           #+#    #+#             */
/*   Updated: 2023/07/07 16:32:37 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stackft.h"

int	ft_stack_valid(t_stack *stack, char mode)
{
	if (!stack)
		return (-1);
	if (mode)
	{
		if (stack->u_data.v && stack->_type && stack->size)
			return (0);
		else
			return (-1);
	}
	else
	{
		if (stack->u_data.v && stack->_type && stack->cap)
			return (0);
		else
			return (-1);
	}
}
