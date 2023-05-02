/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_insert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 22:58:55 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/01 22:58:59 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_insert(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	if (!(*lst)->next)
		return (ft_lstadd_back(lst, new));
	else if (!(*lst)->prev)
		return (ft_lstadd_front(lst, new));
	else
	{
		new->next = (*lst)->next;
		new->prev = *lst;
		(*lst)->next->prev = new;
		(*lst)->next = new;
	}
}
