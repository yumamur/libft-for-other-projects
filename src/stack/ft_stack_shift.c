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

#include "stackft.h"

void	ft_stack_shift_up(t_stack *stack)
{
	void	*tmp;
	char	*i;
	t_uint	ct;

	if (!stack || !stack->data || !stack->_type || !stack->size)
		return ;
	tmp = malloc(stack->_type);
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

void	ft_stack_shift_down(t_stack *stack)
{
	void	*tmp;
	char	*i;
	t_uint	ct;

	if (!stack || !stack->data || !stack->_type || !stack->size)
		return ;
	tmp = malloc(stack->_type);
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

void	ft_stack_nshift_up(t_stack *stack, t_uint n)
{
	if (!n || !stack || !stack->data || !stack->_type || !stack->size)
		return ;
	while (n--)
		ft_stack_shift_up(stack);
}

void	ft_stack_nshift_down(t_stack *stack, t_uint n)
{
	if (!n || !stack || !stack->data || !stack->_type || !stack->size)
		return ;
	while (n--)
		ft_stack_shift_down(stack);
}
