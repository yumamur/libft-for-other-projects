/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envvar_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 00:30:35 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/11 01:16:45 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_envvar_namelen(t_c_char *pt)
{
	int	i;

	if (!pt)
		return (-1);
	i = 0;
	if (pt[i] != '$')
		return (-1);
	if (pt[i] == '$' && (pt[i + 1] == '_' || ft_isalpha(pt[i + 1])))
		while (pt[++i + 1] == '_' || ft_isalnum(pt[i + 1]))
			;
	return (i);
}
