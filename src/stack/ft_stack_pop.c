/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:51:20 by yumamur           #+#    #+#             */
/*   Updated: 2023/07/07 18:46:13 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stackft.h"

t_pop	ft_stack_pop(t_stack *st)
{
	t_pop	ret;

	if (ft_stack_valid(st, 1))
	{
		ret.status = -1;
		return (ret);
	}
	ret.status = 0;
	ft_memcpy((void *)ret.buf, &(st->u_data.v[st->index]), st->_type);
	_call_internal(ST_DELONE, st, 0);
	return (ret);
}
