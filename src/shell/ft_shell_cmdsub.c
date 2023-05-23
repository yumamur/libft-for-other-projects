/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell_cmdsub.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:12:15 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/19 19:12:16 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shellft.h"
#include "def/cmdsub.h"
#include <stdio.h>

static void	if_quote_matches(t_cmdsub *cmd, t_c_char *p, int c, t_ulint l)
{
	cmd->qt.bgn = ft_memchr(p, c, l);
	if (cmd->qt.bgn)
		cmd->qt.end = ft_strchr(cmd->qt.bgn + 1, c);
	if (!cmd->qt.end)
	{
		cmd->pt_err = cmd->qt.bgn;
		cmd->qt.bgn = NULL;
	}
}

static int	find_quotes(t_cmdsub *cmd, t_quote *qt)
{
	t_c_char	*pt;

	if (!qt->bgn && !qt->end)
	{
		if (ft_strnchr(cmd->bgn, 34, cmd->end - cmd->bgn))
			if_quote_matches(cmd, cmd->bgn, 34, cmd->end - cmd->bgn);
		else if (ft_strnchr(cmd->bgn, 39, cmd->end - cmd->bgn))
			if_quote_matches(cmd, cmd->bgn, 39, cmd->end - cmd->bgn);
		return (1);
	}
	else
	{
		pt = qt->bgn;
		if (ft_strnchr(qt->end + 1, 34, cmd->end - qt->end))
			if_quote_matches(cmd, qt->end + 1, 34, cmd->end - qt->end);
		else if (ft_strnchr(qt->end + 1, 39, cmd->end - qt->end))
			if_quote_matches(cmd, qt->end + 1, 39, cmd->end - qt->end);
		if (pt == qt->bgn || !qt->end)
			return (0);
		else
			return (1);
	}
}

static int	mark_quote(t_cmdsub *cmd, t_quote *qt)
{
	int	fin;

	if (!cmd->end)
		return (__set_errno(cmd, UNFINISHED_SUB));
	fin = find_quotes(cmd, qt);
	if (!fin)
		return (1);
	if (cmd->pt_err)
		return (__set_errno(cmd, UNMATCHED_QT));
	if (qt->end > cmd->end)
	{
		cmd->end = ft_strchr(qt->end, ')');
		if (!cmd->end)
			return (__set_errno(cmd, UNFINISHED_SUB));
	}
	return (!!qt->end && !!qt->end * mark_quote(cmd, qt));
}

static void	fix_paranthesis(t_cmdsub *cmd)
{
	t_cmdsub	*pt;

	pt = NULL;
	while (cmd)
	{
		pt = cmd->next;
		while (pt)
		{
			if (cmd->end == pt->end)
				cmd->end = ft_strchr(pt->end + 1, ')');
			if (!cmd->end)
				__set_errno(cmd, UNFINISHED_SUB);
			else
				mark_quote(cmd, &cmd->qt);
			if (cmd->errno)
				return ;
			pt = pt->next;
		}
		cmd = cmd->next;
	}
}

t_cmdsub	*_cmdsub_parse(t_c_char *buf)
{
	t_cmdsub	*cmd;
	t_cmdsub	*cur;
	t_c_char	*n_sub;

	cmd = malloc(sizeof(t_cmdsub));
	if (!__cmdsub_init(cmd, buf))
		return (__set_return(cmd));
	cur = cmd;
	if (!mark_quote(cmd, &cmd->qt))
		return (__set_return(cmd));
	while (ft_strnstr_pt(cur->bgn + 2, "$(", cmd->end - cur->bgn - 2, n_sub))
	{
		__cmdsub_init(cur->next, n_sub);
		cur = cur->next;
		mark_quote(cur, &cur->qt);
		fix_paranthesis(cmd);
	}
	cur = cmd;
	while (cur)
	{
		printf("cur->bgn = %s\ncur->end = %s\n", cur->bgn, cur->end);
		cur = cur->next;
	}
	return (__set_return(cmd));
}
