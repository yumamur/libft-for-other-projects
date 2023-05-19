#include "../../include/shellft.h"

static int	find_quote(const char *buf, t_quote ctl_q)
{
	while (buf)
	{
		if (ft_strchr(buf, 34))
		{
			ctl_q.start = ft_strchr(buf, 34);
			ctl_q.end = ft_strchr(ctl_q.start + 1, 34);
		}
		else if (ft_strchr(buf, 39))
		{
			ctl_q.start = ft_strchr(buf, 39);
			ctl_q.end = ft_strchr(ctl_q.start + 1, 39);
		}
		if (ctl_q.start && !ctl_q.end)
			return (-1);
	}
}

int	ft_shell_cmdsub(int fd, const char *buf, const char *envp[])
{
	t_quote	ctl_q;

	return ();
}
