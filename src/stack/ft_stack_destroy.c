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

int	ft_stack_destroy(t_stack **stack)
{
	if (!stack || !*stack)
		return (-1);
	if ((*stack)->data)
		free((void *)(*stack)->data);
	free(*stack);
	return (0);
}