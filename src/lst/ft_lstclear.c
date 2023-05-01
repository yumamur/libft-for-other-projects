/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 05:54:28 by yumamur           #+#    #+#             */
/*   Updated: 2023/04/30 23:17:09 by yusuf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*pt;

	if (!lst || !*lst || !del)
		return ;
	while (lst && *lst)
	{
		pt = (*lst)->next;
		ft_lstdelone((*lst), del);
		*lst = pt;
	}
}
