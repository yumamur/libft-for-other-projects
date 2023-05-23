/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 23:02:21 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/01 23:02:35 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(t_uint, char*))
{
	t_uint	i;

	if (!s || !f)
		return ;
	i = -1;
	while (s[++i] != '\0')
		(*f)(i, &s[i]);
}
