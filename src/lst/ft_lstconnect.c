/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstconnect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:18:33 by yusuf             #+#    #+#             */
/*   Updated: 2023/04/30 23:17:23 by yusuf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstconnect(t_list *lst)
{
	if (!lst)
		return ;
	lst->next->prev = lst->prev;
	lst->prev->next = lst->next;
	lst->next = NULL;
	lst->prev = NULL;
}
