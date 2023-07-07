/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackft.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yumamur <yumamur@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:21:42 by yumamur           #+#    #+#             */
/*   Updated: 2023/07/07 18:42:07 by yumamur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKFT_H
# define STACKFT_H

# include "memft.h"
# include <unistd.h>

# ifndef _STRUCT_STACK
#  define _STRUCT_STACK

/*	Define TYPE_SIZE macro BEFORE creating libft.a
 */
#  define _TYPE_SIZE_MAX 128
#  ifndef MAX_TYPE_SIZE
#   define MAX_TYPE_SIZE 8
#  elif MAX_TYPE_SIZE > _TYPE_SIZE_MAX
#   undef MAX_TYPE_SIZE
#   define MAX_TYPE_SIZE _TYPE_SIZE_MAX
#  endif /* MAX_TYPE_SIZE */

typedef struct s_stack
{
	union
	{
		void		*v;
		t_c_char	*c;
		t_c_uchar	*uc;
		t_c_short	*s;
		t_c_ushort	*us;
		t_c_int		*i;
		t_c_uint	*ui;
		t_c_long	*l;
		t_c_ulong	*ul;
	}	u_data;
	t_c_uint	size;
	t_c_uint	cap;
	t_c_ulong	index;
	t_c_ulong	_type;
}	t_stack;

typedef struct s_pop
{
	int		status;
	char	buf[MAX_TYPE_SIZE];
}	t_pop;

# endif /* _STRUCT_STACK */

int		ft_stack_clear(t_stack *stack);
int		ft_stack_destroy(t_stack **stack);
int		ft_stack_exch_bottom(t_stack *st1, t_stack *st2);
int		ft_stack_exch_top(t_stack *st1, t_stack *st2);
int		ft_stack_init(t_stack *st, t_uint cap, t_ulong _type);
t_pop	ft_stack_pop(t_stack *stack);
int		ft_stack_push(t_stack *stack, void *val);
int		ft_stack_shift_ndown(t_stack *stack, t_uint n);
int		ft_stack_shift_nup(t_stack *stack, t_uint n);
int		ft_stack_swap(t_stack *stack, t_uint i1, t_uint i2);
int		ft_stack_xpanda(t_stack *stack, t_uint n);
int		ft_stack_valid(t_stack *stack, char mode);

# define ST_DELONE 1
# define ST_SETTYPE 2
# define ST_SETCAP 3
# define ST_SETSIZE 4

int		_call_internal(int mode, t_stack *st, t_ulong var);

#endif /* STACKFT_H */
