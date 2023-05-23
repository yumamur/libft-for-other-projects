/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell_var.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:21:56 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/20 18:21:57 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shellft.h"

int	ft_shell_var(int fd, t_c_char *buf, t_c_char *envp[])
{
	int			i;
	int			len;
	char		*var;
	t_c_char	*pt;

	i = 1;
	if (buf[i] == 0)
	{
		pt = ft_getenv((t_c_char **)envp, "SHELL");
		write(fd, pt, ft_strlen(pt));
	}
	if (buf[i] == '_' || ft_isalpha(buf[i]))
	{
		len = ft_envvar_namelen(&(buf[i - 1]));
		var = malloc(len + 1);
		ft_strlcpy(var, &(buf[i]), len + 1);
		pt = ft_getenv(envp, var);
		ft_free_pt(var);
		write(fd, pt, ft_strlen(pt));
		i += len;
	}
	return (i);
}
