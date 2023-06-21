/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:51:20 by yumamur           #+#    #+#             */
/*   Updated: 2023/06/17 20:26:43 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/stackft.h"
#include "../../include/internal/stack_utils.h"

t_pop	ft_stack_pop(t_stack *st)
{
	t_pop	ret;

	if (!ft_stack_valid(st, 1))
	{
		ret.status = -1;
		return (ret);
	}
	ret.status = 0;
	ft_memcpy((void *)ret.buf, &(st->data[st->index]), st->_type);
	_stack_delone(st);
	return (ret);
}
