/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 04:36:29 by yumamur           #+#    #+#             */
/*   Updated: 2023/04/30 23:13:04 by yusuf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*pt;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		pt = ft_lstlast(*lst);
		pt->next = new;
		new->prev = pt;
	}
}
