/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:47:27 by yumamur           #+#    #+#             */
/*   Updated: 2023/07/07 18:46:39 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stackft.h"

int	ft_stack_push(t_stack *st, void *val)
{
	static char	ctl;

	if (!st)
		return (-1);
	if (!ctl)
		ctl = 0;
	if (st->size == st->cap)
	{
		if (ctl++ < 3)
			ft_stack_xpanda(st, 1);
		else
			return (-1);
	}
	_call_internal(ST_SETSIZE, st, st->size + 1);
	ft_memcpy(&st->u_data.v[st->index], val, st->_type);
	return (0);
}
