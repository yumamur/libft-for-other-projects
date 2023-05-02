/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstconnect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 22:59:15 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/01 22:59:17 by yumamur          ###   ########.fr       */
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
