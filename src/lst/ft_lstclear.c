/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 23:09:43 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/01 23:09:48 by yumamur          ###   ########.fr       */
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
