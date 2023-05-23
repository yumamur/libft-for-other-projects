/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 23:02:44 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/01 23:02:45 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, t_c_char *src, size_t size)
{
	size_t	i;
	size_t	b;

	if ((!dest || !src) && size == 0)
		return (0);
	i = ft_strlen(dest);
	b = 0;
	if (size <= ft_strlen(dest))
		return (size + ft_strlen(src));
	while (src[b] != '\0' && i + 1 < size)
	{
		dest[i] = src[b];
		i++;
		b++;
	}
	dest[i] = '\0';
	return (ft_strlen(dest) + ft_strlen(&src[b]));
}
