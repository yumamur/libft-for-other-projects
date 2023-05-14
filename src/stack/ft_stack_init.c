/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:47:08 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/14 15:47:13 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/stackft.h"
#include "../../include/def/stackft_internal.h"

/* Don't mind the casting, it saves about 16 bytes
*/
void	ft_stack_init(t_stack *pt_stack, unsigned int cap, unsigned long _type)
{
	if (!pt_stack || !cap || !_type)
		return ;
	_stack_settype(pt_stack, _type);
	_stack_setcap(pt_stack, cap);
	_stack_setsize(pt_stack, 0);
	pt_stack->data = malloc(cap * pt_stack->_type);
}
