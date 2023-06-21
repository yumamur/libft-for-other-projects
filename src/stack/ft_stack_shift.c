/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_shift.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 21:29:50 by yumamur           #+#    #+#             */
/*   Updated: 2023/06/07 21:29:51 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/stackft.h"

int	ft_stack_shift_nup(t_stack *stack, t_uint n)
{
	char	tmp[MAX_TYPE_SIZE];
	char	*i;
	t_uint	ct;

	if (!n || !ft_stack_valid(stack, 1))
		return (-1);
	while (n--)
	{
		ft_memcpy(tmp, stack->data, stack->_type);
		ct = stack->size - 1;
		i = (char *)stack->data;
		while (ct--)
		{
			ft_memcpy(i, i + stack->_type, stack->_type);
			i += stack->_type;
		}
		ft_memcpy(i, tmp, stack->_type);
	}
	return (0);
}

int	ft_stack_shift_ndown(t_stack *stack, t_uint n)
{
	char	tmp[MAX_TYPE_SIZE];
	char	*i;
	t_uint	ct;

	if (!n || !ft_stack_valid(stack, 1))
		return (-1);
	while (n--)
	{
		ft_memcpy(tmp, stack->data + stack->index, stack->_type);
		ct = stack->size - 1;
		i = (char *)&stack->data[stack->index];
		while (ct--)
		{
			ft_memcpy(i, i - stack->_type, stack->_type);
			i -= stack->_type;
		}
		ft_memcpy(i, tmp, stack->_type);
	}
	return (0);
}
