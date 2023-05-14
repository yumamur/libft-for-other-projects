/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:46:44 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/14 15:47:33 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/stackft.h"
#include "../../include/def/stackft_internal.h"

void	ft_stack_clear(t_stack *pt_stack)
{
	while (pt_stack->size)
		_stack_delone(pt_stack);
}
