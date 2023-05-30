/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_to_s1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:00:26 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/08 18:00:27 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strjoin_frees2(t_c_char *s1, char *s2)
{
	char	*str;
	int		i1;
	int		i2;

	if (!s1)
		s1 = ft_strdup("");
	if (!s1 || !s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i1 = -1;
	while (s1[++i1])
		str[i1] = s1[i1];
	i2 = 0;
	while (s2[i2])
		str[i1++] = s2[i2++];
	str[i1] = '\0';
	free(s2);
	return (str);
}

char	*ft_strjoin_frees1(char *s1, t_c_char *s2)
{
	char	*str;
	int		i1;
	int		i2;

	if (!s1)
		s1 = ft_strdup("");
	if (!s1 || !s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i1 = -1;
	while (s1[++i1])
		str[i1] = s1[i1];
	i2 = 0;
	while (s2[i2])
		str[i1++] = s2[i2++];
	str[i1] = '\0';
	free(s1);
	return (str);
}
