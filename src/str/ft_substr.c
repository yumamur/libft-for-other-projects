/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 23:03:29 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/01 23:03:31 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(t_c_char *s, t_uint start, size_t len)
{
	char	*ret;
	size_t	size;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	ret = NULL;
	size = ft_strlen((char *)s);
	if (start > size)
		return (ft_strdup(""));
	if (size - start < len)
		ret = malloc(size - start + 1);
	else
		ret = malloc(len + 1);
	if (ret == NULL)
		return (NULL);
	ft_strlcpy(ret, s + start, len + 1);
	return (ret);
}
