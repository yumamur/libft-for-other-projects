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

static int	find_quote(const char *buf, t_cmdsub cmd, t_quote qt)
{
	if (ft_strnchr(buf, 34, cmd.end - buf))
	{
		qt.start = ft_strnchr(buf, 34, cmd.end - buf);
		qt.end = ft_strchr(qt.start + 1, 34);
	}
	else if (ft_strnchr(buf, 39, cmd.end - buf))
	{
		qt.start = ft_strnchr(buf, 39, cmd.end - buf);
		qt.end = ft_strchr(qt.start + 1, 39);
	}
	if (qt.start && !qt.end)
		return (-1);
	if (qt.end && qt.end > cmd.end)
	{
		cmd.end = ft_strchr(qt.end, ')');
		if (!cmd.end)
			return (-2);
	}
	if (qt.start && qt.end)
		ft_memset(&cmd.mark[qt.start - buf], 1, qt.end - qt.start + 1);
	return (!!qt.start);
}
static int	mark_subs(const char *buf, char *mark_buf)
{
	const char	*pt;

	pt = ft_strstr(buf, "$(");
}

// static int	mark_quote(const char *buf, char *mark_buf)
// {
// 	t_quote	ctl_q;
// 	size_t	i;
// 	size_t	len;

// 	i = 0;
// 	if (ft_strchr(buf, 34))
// 	{
// 		i = ft_strchr(buf, 34) - buf;
// 		ctl_q.start = &buf[i];
// 		ctl_q.end = ft_strchr(&buf[i + 1], 34);
// 	}
// 	else if (ft_strchr(buf, 39))
// 	{
// 		i = ft_strchr(buf, 39) - buf;
// 		ctl_q.start = &buf[i];
// 		ctl_q.end = ft_strchr(&buf[i + 1], 39);
// 	}
// 	if (ctl_q.start && !ctl_q.end)
// 		return (-1);
// 	else if (ctl_q.start && ctl_q.end)
// 	{
// 		len = ctl_q.end - ctl_q.start + 1;
// 		ft_memset(&mark_buf[i], 1, len);
// 		return (mark_quote(&buf[len], &mark_buf[len]));
// 	}
// 	return (0);
// }

int	ft_shell_cmdsub(int fd, const char *buf, const char *envp[])
{
	t_cmdsub	cmd;
	int			ret;

	cmd.mark = ft_calloc(ft_strlen(buf), 1);
	ret = find_quote(buf, cmd, cmd.qt);
	if (ret < 0)
		return (ret);
	if (mark_subs(buf, cmd.mark))
		return (-3);
	return (1);
}
