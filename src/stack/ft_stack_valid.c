/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:29:23 by yumamur           #+#    #+#             */
/*   Updated: 2023/06/13 12:29:24 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stackft.h"

int	ft_stack_valid(t_stack *stack, char mode)
{
	if (mode)
		return ((stack->data && stack->_type && stack->size));
	else
		return ((stack->data && stack->_type && stack->cap));
}
