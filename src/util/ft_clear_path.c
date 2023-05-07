/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:54:13 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/07 19:54:14 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_clear_path(char **path)
{
	char	*tmp;

	tmp = ft_strdup(ft_strrchr(*path, '/') + 1);
	free(*path);
	*path = ft_strdup(tmp);
	free(tmp);
}
