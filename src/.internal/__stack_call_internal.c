/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __stack_call_internal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 13:42:13 by yumamur           #+#    #+#             */
/*   Updated: 2023/06/17 20:05:15 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include "stackft.h"
#include "internal/stack_utils.h"

int	_call_internal(void (*f)(), t_stack *st, ...)
{
	va_list	args;

	if (!f)
		return (0);
	if ((void (*)(t_stack *, t_uint))f == _stack_setcap
		|| ((void (*)(t_stack *, t_uint))f == _stack_setsize))
	{
		va_start(args, st);
		f(st, va_arg(args, t_uint));
		va_end(args);
	}
	else if ((void (*)(t_stack *, t_ulong))f == _stack_settype)
	{
		va_start(args, st);
		f(st, va_arg(args, t_ulong));
		va_end(args);
	}
	else if ((void (*)(t_stack *))f == _stack_delone
			|| (void (*)(t_stack *))f == _update_index)
		f(st);
	return (1);
}
