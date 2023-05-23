/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __cmdsub_internal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 22:49:58 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/21 22:50:00 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "def/cmdsub.h"

t_cmdsub	*__set_free(t_cmdsub *cmd)
{
	t_cmdsub	*pt;

	if (!cmd)
		return (NULL);
	while (cmd->next)
	{
		pt = cmd->next;
		while (pt->next)
			pt = pt->next;
		free(pt);
	pt = NULL;
	}
	free(cmd);
	return (NULL);
}

t_cmdsub	*__set_return(t_cmdsub *cmd)
{
	t_cmdsub	*pt;

	pt = cmd;
	while (pt)
	{
		if (pt->errno == UNMATCHED_QT)
		{
			write(2, "zsh: unmatched ", 15);
			write(2, pt->pt_err, 1);
			write(2, " near \033[31;1;4m(\033[m", 19);
			write(2, pt->pt_err, ft_strlen_max(pt->pt_err, 10));
			write(2, "\033[31;1;4m)\033[m\n", 15);
			return (__set_free(cmd));
		}
		else if (pt->errno)
		{
			write(2, "zsh: parse error\n", 17);
			return (__set_free(cmd));
		}
		if (pt->next)
			pt = pt->next;
		else
			break ;
	}
	return (cmd);
}

int	__set_errno(t_cmdsub *cmd, int num)
{
	if (!cmd)
		return (0);
	cmd->errno = num;
	return (0);
}

int	__cmdsub_init(t_cmdsub *pt, t_c_char *buf)
{
	if (!buf)
		return (0);
	if (!pt)
		pt = malloc(sizeof(t_cmdsub));
	pt->bgn = buf;
	pt->end = ft_strchr(pt->bgn, ')');
	if (!pt->end)
		return (__set_errno(pt, UNFINISHED_SUB));
	pt->errno = 0;
	pt->pt_err = NULL;
	pt->next = NULL;
	pt->qt.bgn = NULL;
	pt->qt.end = NULL;
	return (1);
}
