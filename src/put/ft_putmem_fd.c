/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmem_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 23:01:20 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/01 23:01:23 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	Print 'n' bytes in binary to given fd, seperated by given 'sep'. Prints
 *	a single line, if no 'sep' is given.
 */
void	ft_putmem_fd(int fd, void *mem, size_t n, t_c_char *sep)
{
	int		shift;
	size_t	i;
	t_uchar	tmp;

	if (!mem)
		return ;
	i = 0;
	while (i < n)
	{
		shift = 8;
		while (--shift >= 0)
		{
			tmp = ((*(int *)&mem[i] & (1 << shift)) >> shift) + 48;
			write(fd, &tmp, 1);
		}
		i++;
		if (sep && i < n)
			write(fd, sep, ft_strlen(sep));
	}
	write(fd, "\n", 1);
}
