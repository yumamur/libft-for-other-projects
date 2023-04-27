/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 05:00:29 by yumamur           #+#    #+#             */
/*   Updated: 2023/04/12 19:32:43 by yusuf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*node;
	int		x;

	x = 0;
	node = lst;
	while (node != NULL)
	{
		x++;
		node = node->next;
	}
	return (x);
}
