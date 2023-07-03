/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:22:06 by yumamur           #+#    #+#             */
/*   Updated: 2023/06/17 16:24:43 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_UTILS_H
# define STACK_UTILS_H

# include "../def/typeft.h"

# ifndef _STRUCT_STACK
#  define _STRUCT_STACK

typedef struct s_stack
{
	void		*data;
	t_c_uint	size;
	t_c_uint	cap;
	t_c_ulong	index;
	t_c_ulong	_type;
}	t_stack;
# endif /* _STRUCT_STACK */

int	_update_index(t_stack *pt_stack);
int	_stack_delone(t_stack *pt_stack);
int	_stack_settype(t_stack *pt_stack, t_ulong _type);
int	_stack_setcap(t_stack *pt_stack, t_uint cap);
int	_stack_setsize(t_stack *pt_stack, t_uint size);
int		_call_internal(void (*f)(), t_stack *st, ...);
#endif /* STACKFT_INTERNAL_H */
