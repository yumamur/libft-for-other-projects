/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shellft.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:00:25 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/20 18:21:42 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELLFT_H
# define SHELLFT_H

# include "libft.h"

# ifndef SHELL_STRUCTS
#  define SHELL_STRUCTS

typedef struct s_quote
{
	const char		*bgn;
	const char		*end;
}	t_quote;

typedef struct s_cmdsub
{
	const char		*bgn;
	const char		*end;
	char			*mark;
	const char		*pt_err;
	int				errno;
	struct s_quote	qt;
	struct s_cmdsub	*next;
}	t_cmdsub;
# endif

char		*ft_file_name(char *path);
const char	*ft_getenv(const char *envp[], const char *name);
ssize_t		ft_envvar_namelen(const char *pt);
int			ft_shell_var(int fd, const char *buf, const char *envp[]);
int			ft_shell_cmdsub(int fd, const char *buf, const char *envp[]);
#endif
