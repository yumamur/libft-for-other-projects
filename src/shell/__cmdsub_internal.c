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

#include "../../include/def/cmdsub.h"

int	_set_return(t_cmdsub *cmd)
{
	while (cmd)
	{
		if (cmd->errno == UNMATCHED_QT)
		{
			write(2, "zsh: unmatched ", 15);
			write(2, cmd->pt_err, 1);
			write(2, " near \033[31;1;4m(\033[m", 19);
			write(2, cmd->pt_err, ft_strlen_max(cmd->pt_err, 10));
			write(2, "\033[31;1;4m)\033[m\n", 15);
			return (UNMATCHED_QT);
		}
		else if (cmd->errno)
		{
			write(2, "zsh: parse error\n", 17);
			return (cmd->errno);
		}
		if (cmd->next)
			cmd = cmd->next;
		else
			break ;
	}
	return (1);
}

int	_set_errno(t_cmdsub *cmd, int num)
{
	if (!cmd)
		return (0);
	cmd->errno = num;
	return (num);
}

int	_cmdsub_init(t_cmdsub *pt, const char *buf, char *mark)
{
	if (!buf)
		return (0);
	pt->bgn = buf + 2;
	pt->end = ft_strchr(pt->bgn, ')');
	if (!mark)
	{
		pt->mark = malloc(ft_strlen(pt->bgn));
		ft_memset(pt->mark, 'a', ft_strlen(pt->bgn));
	}
	else
		pt->mark = mark;
	pt->errno = 0;
	pt->pt_err = NULL;
	pt->next = NULL;
	pt->qt.bgn = NULL;
	pt->qt.end = NULL;
	return (1);
}
