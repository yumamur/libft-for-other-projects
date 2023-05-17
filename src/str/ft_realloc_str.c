/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:59:08 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/10 20:59:15 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_realloc_str(char *str, size_t size)
{
	void	*buf;

	if (!size && !str)
		return (NULL);
	if (!size && str)
	{
		free(str);
		str = NULL;
		return (str);
	}
	if (!str && size)
	{
		str = malloc(size);
		if (!str)
			return (NULL);
		else
			return (str);
	}
	buf = ft_strdup(str);
	free(str);
	str = malloc(size);
	ft_memcpy(str, buf, ft_strlen(buf));
	free(buf);
	return (str);
}
