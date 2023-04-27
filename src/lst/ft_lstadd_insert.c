/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_insert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 19:22:45 by yusuf             #+#    #+#             */
/*   Updated: 2023/04/16 18:23:36 by yusuf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

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
