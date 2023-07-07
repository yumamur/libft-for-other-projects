/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_xpanda.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:46:53 by yumamur           #+#    #+#             */
/*   Updated: 2023/07/07 18:43:13 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stackft.h"

int	ft_stack_xpanda(t_stack *stack, t_uint n)
{
	void	*buf;
	void	*pt_buf;

	if (!stack || !n || !stack->u_data.v || _call_internal(ST_SETCAP, stack, n))
		return (-1);
	buf = malloc(stack->cap * stack->_type);
	if (!buf)
		return (-1);
	pt_buf = ft_memcpy(buf, stack->u_data.v, stack->size * stack->_type);
	if (!pt_buf || pt_buf != buf)
	{
		free(buf);
		return (-1);
	}
	free(stack->u_data.v);
	stack->u_data.v = buf;
	buf = NULL;
	return (0);
}
