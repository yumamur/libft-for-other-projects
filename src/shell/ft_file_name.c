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

#include "../../include/shellft.h"

char	*ft_file_name(char *path)
{
	char	*ret;

	if (ft_strrchr(path, '/'))
		ret = ft_strrchr(path, '/') + 1;
	else
		ret = path;
	return (ret);
}
