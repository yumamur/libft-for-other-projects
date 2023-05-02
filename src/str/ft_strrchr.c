/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 23:03:12 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/01 23:03:20 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	index;

	index = ft_strlen(s);
	if ((char) c == '\0')
		return ((char *) s + index);
	while (index-- > 0)
		if (s[index] == (char) c)
			return ((char *) s + index);
	if (s[0] == (char) c)
		return ((char *)s);
	return (NULL);
}
