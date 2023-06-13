/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:47:03 by yumamur           #+#    #+#             */
/*   Updated: 2023/06/13 16:47:04 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stackft.h"

void	ft_stack_destroy(t_stack *stack)
{
	if (!stack)
		return ;
	ft_stack_clear(stack);
	if (stack->data)
		free((void *)stack->data);
	free(stack);
}
