/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:56:14 by yumamur           #+#    #+#             */
/*   Updated: 2022/12/25 00:01:01 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
