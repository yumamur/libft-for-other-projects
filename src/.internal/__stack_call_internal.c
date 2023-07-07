/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __stack_call_internal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 13:42:13 by yumamur           #+#    #+#             */
/*   Updated: 2023/07/07 18:47:52 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stackft.h"
#include "internal/stack_utils.h"

int	_call_internal(int mode, t_stack *stack, t_ulong var)
{
	if (!mode || !stack)
		return (-1);
	if (mode == ST_DELONE)
		return (_stack_delone(stack));
	else if (mode == ST_SETSIZE)
		return (_stack_setsize(stack, var));
	else if (mode == ST_SETTYPE)
		return (_stack_settype(stack, var));
	else if (mode == ST_SETCAP)
		return (_stack_setcap(stack, var));
	return (-1);
}
