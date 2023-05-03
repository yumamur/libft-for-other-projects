/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 22:54:03 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/01 23:11:14 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*ft_getenv_2(const char *envp[], const char *name)
{
	const char		**ptenv;
	size_t			len;
	unsigned short	name_start;
	unsigned short	ptenv_start;

	ptenv = envp;
	name_start = (name[0] * 256) + name[1];
	len = ft_strlen(name);
	while (*ptenv)
	{
		ptenv_start = ((*ptenv)[0] * 256) + (*ptenv)[1];
		if (ptenv_start == name_start && (*ptenv)[len] == '='
			&& !ft_strncmp(*ptenv + 2, name + 2, len - 2))
			return (&(*ptenv)[len + 1]);
		ptenv++;
	}
	return (NULL);
}

const char	*ft_getenv(const char *envp[], const char *name)
{
	const char		**ptenv;
	unsigned short	name_start;
	unsigned short	ptenv_start;

	if (!envp || !envp[0] || !name || name[0] == '\0')
		return (NULL);
	if (name[1] == '\0')
	{
		ptenv = envp;
		((unsigned char *)&name_start)[0] = *(unsigned char *)name;
		((unsigned char *)&name_start)[1] = '=';
		while (*ptenv)
		{
			ptenv_start = *((unsigned short *)*ptenv);
			if (ptenv_start == name_start)
				return (&(*ptenv)[2]);
			ptenv++;
		}
	}
	else
		return (ft_getenv_2(envp, name));
	return (NULL);
}
