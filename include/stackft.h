/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackft.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:21:42 by yumamur           #+#    #+#             */
/*   Updated: 2023/06/16 22:21:51 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKFT_H
# define STACKFT_H

# include "memft.h"
# include <unistd.h>

# ifndef _STRUCT_STACK
#  define _STRUCT_STACK

/*	Define TYPE_SIZE macro BEFORE including stackft.h
 */
#  define __SIZE_MAX 128
#  ifndef MAX_TYPE_SIZE
#   define MAX_TYPE_SIZE 1
#  elif MAX_TYPE_SIZE > __SIZE_MAX
#   undef MAX_TYPE_SIZE
#   define MAX_TYPE_SIZE __SIZE_MAX
#  endif /* MAX_TYPE_SIZE */

typedef struct s_stack
{
	t_c_char	*data;
	t_c_uint	size;
	t_c_uint	cap;
	t_c_ulint	index;
	t_c_ulong	_type;
}	t_stack;

typedef struct s_pop
{
	int		status;
	char	buf[MAX_TYPE_SIZE];
}	t_pop;

# endif /* _STRUCT_STACK */

void	ft_stack_clear(t_stack *stack);
void	ft_stack_destroy(t_stack **stack);
void	ft_stack_exch_bottom(t_stack *st1, t_stack *st2);
void	ft_stack_exch_top(t_stack *st1, t_stack *st2);
void	ft_stack_init(t_stack *st, t_uint cap, t_ulong _type);
t_pop	ft_stack_pop(t_stack *stack);
int		ft_stack_push(t_stack *stack, void *val);
int		ft_stack_shift_ndown(t_stack *stack, t_uint n);
int		ft_stack_shift_nup(t_stack *stack, t_uint n);
int		ft_stack_swap(t_stack *stack, t_uint i1, t_uint i2);
void	ft_stack_xpanda(t_stack *stack, t_uint n);
int		ft_stack_valid(t_stack *stack, char mode);

#endif /* STACKFT_H */
