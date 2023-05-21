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

#include "../../include/shellft.h"
#include "../../include/def/cmdsub.h"

void	if_quoted(t_cmdsub *cmd, const char *ptr, int c, unsigned long int len)
{
	cmd->qt.bgn = ft_memchr(ptr, c, len);
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
	const char	*pt;

	if (!qt->bgn && !qt->end)
	{
		if (ft_strnchr(cmd->bgn, 34, cmd->end - cmd->bgn))
			if_quoted(cmd, cmd->bgn, 34, cmd->end - cmd->bgn);
		else if (ft_strnchr(cmd->bgn, 39, cmd->end - cmd->bgn))
			if_quoted(cmd, cmd->bgn, 39, cmd->end - cmd->bgn);
		return (1);
	}
	else
	{
		pt = qt->bgn;
		if (ft_strnchr(qt->end + 1, 34, cmd->end - qt->end))
			if_quoted(cmd, qt->end + 1, 34, cmd->end - qt->end);
		else if (ft_strnchr(qt->end + 1, 39, cmd->end - qt->end))
			if_quoted(cmd, qt->end + 1, 39, cmd->end - qt->end);
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
		return (_set_errno(cmd, UNFINISHED_SUB));
	fin = find_quotes(cmd, qt);
	if (!fin)
		return (0);
	if (cmd->pt_err)
		return (_set_errno(cmd, UNMATCHED_QT));
	if (qt->end > cmd->end)
	{
		cmd->end = ft_strchr(qt->end, ')');
		if (!cmd->end)
			return (_set_errno(cmd, UNFINISHED_SUB));
	}
	if (qt->bgn && qt->end)
		ft_memset(&cmd->mark[qt->bgn - cmd->bgn], 'q', qt->end - qt->bgn + 1);
	return (!!qt->end && !!qt->end * mark_quote(cmd, qt));
}

static void	fix_paranthesis(t_cmdsub *cmd)
{
	t_cmdsub		*pt;

	pt = NULL;
	while (cmd)
	{
		if (cmd->next)
			pt = cmd->next;
		while (pt)
		{
			if (cmd->end == pt->end)
				cmd->end = ft_strchr(pt->end + 1, ')');
			if (!cmd->end)
				_set_errno(cmd, UNFINISHED_SUB);
			else
				mark_quote(cmd, &cmd->qt);
			if (cmd->errno)
				return ;
			if (pt->next)
				pt = pt->next;
			else
				break ;
		}
		cmd = cmd->next;
	}
}

int	ft_shell_cmdsub(int fd, const char *buf, const char *envp[])
{
	t_cmdsub	cmd;
	t_cmdsub	*cur;
	const char	*n_sub;

	if (!_cmdsub_init(&cmd, buf, NULL))
		return (-1);
	cur = &cmd;
	if (mark_quote(&cmd, &cmd.qt) < 0)
		return (_set_return(&cmd));
	n_sub = ft_strnstr(cmd.bgn, "$(", cmd.end - cmd.bgn);
	while (n_sub)
	{
		cur->next = malloc(sizeof(t_cmdsub));
		_cmdsub_init(cur->next, n_sub, &(cmd.mark[n_sub - cmd.bgn + 2]));
		cur = cur->next;
		mark_quote(cur, &cur->qt);
		fix_paranthesis(&cmd);
		n_sub = ft_strnstr(cur->bgn, "$(", cmd.end - cur->bgn);
	}
	write(fd, *envp, 1);
	return (_set_return(&cmd));
}
