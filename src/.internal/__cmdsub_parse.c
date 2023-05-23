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

#include "../../include/def/cmdsub.h"

static void	if_quote_matches(t_cmdsub *cmd, t_c_char *p, int c, t_ulint l)
{
	cmd->qt.bgn = ft_memchr(p, c, l);
	if (cmd->qt.bgn)
		cmd->qt.end = ft_strchr(cmd->qt.bgn + 1, c);
	if (!cmd->qt.end)
		cmd->pt_err = cmd->qt.bgn;
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
		if (!qt->bgn && !qt->end)
			return (0);
		return (1);
	}
	else if (qt->bgn && !qt->end)
		return (!__set_errno(cmd, UNMATCHED_QT));
	else
	{
		pt = qt->bgn;
		if (ft_strnchr(qt->end + 1, 34, cmd->end - qt->end))
			if_quote_matches(cmd, qt->end + 1, 34, cmd->end - qt->end);
		else if (ft_strnchr(qt->end + 1, 39, cmd->end - qt->end))
			if_quote_matches(cmd, qt->end + 1, 39, cmd->end - qt->end);
		if (pt == qt->bgn || !qt->end)
			return (0);
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

static int	fix_paranthesis(t_cmdsub *cmd)
{
	t_cmdsub	*pt1;
	t_cmdsub	*pt2;

	pt1 = cmd;
	while (pt1)
	{
		pt2 = cmd;
		while (pt2)
		{
			if (pt1 != pt2 && pt1->end == pt2->end)
			{
				if (pt1->bgn > pt2->bgn)
					pt2->end = ft_strchr(pt1->end + 1, ')');
				else
					pt1->end = ft_strchr(pt2->end + 1, ')');
				mark_quote(pt1, &pt1->qt);
				fix_paranthesis(cmd);
			}
			if (!pt1->end || !pt2->end)
				return (__set_errno(pt1, UNFINISHED_SUB));
			pt2 = pt2->next;
		}
		pt1 = pt1->next;
	}
	return (1);
}

t_cmdsub	*_cmdsub_parse(t_c_char *buf)
{
	t_cmdsub	*cmd;
	t_cmdsub	*cur;
	t_c_char	*n_sub;

	if (!__cmdsub_init(&cmd, buf))
		return (__set_return(cmd));
	cur = cmd;
	if (!mark_quote(cmd, &cmd->qt))
		return (__set_return(cmd));
	while (ft_strnstr_pt(cur->bgn + 2, "$(", cmd->end - cur->bgn - 2, &n_sub))
	{
		__cmdsub_init(&(cur->next), n_sub);
		cur = cur->next;
		mark_quote(cur, &cur->qt);
		if (cur->errno)
			break ;
		fix_paranthesis(cmd);
	}
	cur = cmd;
	while (cur)
	{
		mark_quote(cur, &cur->qt);
		cur = cur->next;
	}
	return (__set_return(cmd));
}
