/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:51:20 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/14 15:51:21 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stackft.h"
#include "internal/stack_utils.h"

void	*ft_stack_pop(t_stack *stack)
{
	void	*pt;

	if (!stack || !stack->data || !stack->size)
	{
		write(2, "\nNo data to pop\n", 16);
		return (NULL);
	}
	pt = ft_memdup(&(stack->data[stack->index]), stack->_type);
	_stack_delone(stack);
	return (pt);
}
