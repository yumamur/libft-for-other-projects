/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_xpanda.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:46:53 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/14 15:46:59 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stackft.h"
#include "internal/stack_utils.h"

int	ft_stack_xpanda(t_stack *stack, t_uint n)
{
	void	*buf;
	t_uint	*pt;

	if (!stack || !n || !stack->data)
		return (-1);
	pt = (t_uint *)&(stack->cap);
	*pt += n;
	buf = malloc(stack->cap * stack->_type);
	buf = ft_memcpy(buf, stack->data, stack->size * stack->_type);
	if (!buf)
		return (-1);
	free((void *)stack->data);
	stack->data = buf;
	buf = NULL;
	return (0);
}
