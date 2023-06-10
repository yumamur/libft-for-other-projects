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

#include "internal/cmdsub.h"

void	*__set_free(t_cmdsub **cmd)
{
	t_cmdsub	*pt;
	t_cmdsub	*pt2;

	if (!cmd)
		return (NULL);
	while (1)
	{
		pt = *cmd;
		pt2 = *cmd;
		while (pt->next)
			pt = pt->next;
		if (pt == *cmd)
			break ;
		while (pt2->next != pt)
			pt2 = pt2->next;
		ft_free_pt(pt);
		pt2->next = NULL;
	}
	free(*cmd);
	*cmd = NULL;
	return (NULL);
}

char	*__set_return(t_cmdsub **cmd)
{
	t_cmdsub	*pt;

	pt = *cmd;
	while (pt)
	{
		if (pt->errno == UNMATCHED_QT)
		{
			write(2, "zsh: unmatched ", 15);
			write(2, pt->pt_err, 1);
			write(1, "\n", 1);
		}
		if (pt->errno)
		{
			write(2, "zsh: parse error\n", 17);
			return (__set_free(cmd));
		}
		if (pt->next)
			pt = pt->next;
		else
			break ;
	}
	if ((*cmd)->next)
		__set_free(&(*cmd)->next);
	return (NULL);
}

int	__set_errno(t_cmdsub *cmd, int num)
{
	if (!cmd)
		return (0);
	cmd->errno = num;
	return (0);
}

int	__cmdsub_init(t_cmdsub **pt, t_c_char *buf)
{
	if (!buf)
		return (0);
	*pt = malloc(sizeof(t_cmdsub));
	(*pt)->bgn = buf;
	(*pt)->end = ft_strchr((*pt)->bgn, ')');
	(*pt)->errno = 0;
	(*pt)->next = NULL;
	(*pt)->qt.bgn = NULL;
	(*pt)->qt.end = NULL;
	if (!(*pt)->end)
		return (__set_errno(*pt, UNFINISHED_SUB));
	return (1);
}
