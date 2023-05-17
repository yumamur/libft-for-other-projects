/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackft_internal.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:22:06 by yumamur           #+#    #+#             */
/*   Updated: 2023/05/14 15:22:07 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKFT_INTERNAL_H
# define STACKFT_INTERNAL_H

# ifndef _STRUCT_STACK
#  define _STRUCT_STACK

typedef struct s_stack
{
	const char				*data;
	const unsigned int		size;
	const unsigned int		cap;
	const unsigned long int	index;
	const unsigned long		_type;
}	t_stack;
# endif

void	_update_index(t_stack *pt_stack);
void	_stack_delone(t_stack *pt_stack);
void	_stack_settype(t_stack *pt_stack, unsigned long _type);
void	_stack_setcap(t_stack *pt_stack, unsigned int cap);
void	_stack_setsize(t_stack *pt_stack, unsigned int size);
#endif
