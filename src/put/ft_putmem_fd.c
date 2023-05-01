/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmem_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 21:22:37 by yusuf             #+#    #+#             */
/*   Updated: 2023/05/01 20:13:45 by yusuf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	Print 'n' bytes in binary to given fd, seperated by given 'sep'. Prints
 *	a single line, if no 'sep' is given.
 */
void	ft_putmem_fd(int fd, size_t n, void *mem, const char *sep)
{
	unsigned char	tmp;
	size_t			i;
	int				shift;

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
}
