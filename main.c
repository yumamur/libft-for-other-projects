#include "include/stackft.h"
#include "include/libft.h"

int	main(void)
{
	t_stack	st;
	int	a1;
	int	a2;
	int	a3;
	int	a4;

	a1 = 1;
	a2 = 2;
	a3 = 4;
	a4 = 8;
	ft_stack_init(&st, 4, sizeof(char));
	ft_stack_push(&st, &a1);
	ft_stack_push(&st, &a2);
	ft_stack_push(&st, &a3);
	ft_stack_push(&st, &a4);
	ft_putmem_fd(1, st.data, 20, "\n");
	ft_putstr("\n");
	ft_stack_nshift_down(&st, 2);
	ft_putmem_fd(1, st.data, 20, "\n");
}
