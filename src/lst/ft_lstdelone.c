/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 22:59:20 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/01 22:59:23 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *node, void (*del)(void *))
{
	if (!node || !del)
		return ;
	(*del)(node->content);
	if (node->prev)
		ft_lstconnect(node);
	free(node);
}
