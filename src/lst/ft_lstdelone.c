/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 05:30:49 by yumamur           #+#    #+#             */
/*   Updated: 2023/04/30 23:17:38 by yusuf            ###   ########.fr       */
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
