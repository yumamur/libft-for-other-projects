/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:17:23 by yumamur           #+#    #+#             */
/*   Updated: 2023/06/13 12:17:24 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stackft.h"

int	ft_stack_exch_top(t_stack *st1, t_stack *st2)
{
	void	*tmp;

	if (!st1 || !st2 || st1->_type != st2->_type)
		return (-1);
	if (!ft_stack_valid(st1, 1) || !ft_stack_valid(st2, 1))
		return (-1);
	tmp = malloc(st1->_type);
	if (!tmp)
		return (-1);
	ft_memcpy(tmp, st1->data, st1->_type);
	ft_memcpy((char *)st1->data, st2->data, st1->_type);
	ft_memcpy((char *)st2->data, tmp, st1->_type);
	free(tmp);
	return (0);
}

int	ft_stack_exch_bottom(t_stack *st1, t_stack *st2)
{
	void	*tmp;

	if (!st1 || !st2 || st1->_type != st2->_type)
		return (-1);
	if (!ft_stack_valid(st1, 1) || !ft_stack_valid(st2, 1))
		return (-1);
	tmp = malloc(st1->_type);
	if (!tmp)
		return (-1);
	ft_memcpy(tmp, &st1->data[st1->index], st1->_type);
	ft_memcpy((char *)&st1->data[st1->index],
		&st2->data[st2->index], st1->_type);
	ft_memcpy((char *)&st2->data[st2->index], tmp, st1->_type);
	free(tmp);
	return (0);
}