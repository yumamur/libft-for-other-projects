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

#include "../../include/stackft.h"
#include "../../include/def/stackft_internal.h"

void	ft_stack_xpanda(t_stack *pt_stack, unsigned int n)
{
	void			*buf;
	unsigned int	*pt;

	if (!pt_stack || !n || !pt_stack->data)
		return ;
	pt = (unsigned int *)&(pt_stack->cap);
	*pt += n;
	buf = malloc(pt_stack->cap * pt_stack->_type);
	buf = ft_memcpy(buf, pt_stack->data, pt_stack->size * pt_stack->_type);
	if (!buf)
		return ;
	free((void *)pt_stack->data);
	pt_stack->data = buf;
	buf = NULL;
}
