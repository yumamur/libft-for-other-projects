#include "../../../include/stackft.h"
#include "../../../include/libft.h"

/*char	*get_next_line(int fd);

void	write_prompt(void)
{
	write(1, "stackft (beta) >>", 17);
}

void	run_vis(t_stack *st_arr, int size)
{
	char	*str;

	while (1)
	{
		write_prompt();
		str = get_next_line(0);
		if (!ft_strncmp(str, "exit", 4))
		{
			ft_free_pt(str);
			str = NULL;
		}
		write(1, str, ft_strlen(str));
		if (str)
			ft_free_pt(str);
	}
}*/

t_uint max_bytes(t_stack *st_arr, t_uint n)
{
	t_uint i = 0;
	t_ulong ret = st_arr[0].cap * st_arr[0]._type;

	while (i < n)
	{
		if (ret < st_arr[i].cap * st_arr[i]._type)
			ret = st_arr[i].cap * st_arr[i]._type;
		i++;
	}
	return (ret);
}

t_uint	countdigits(t_ulint nbr)
{
	int i = 1;
	while (nbr >= 10)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

void putdata(t_stack *st_arr, t_uint n)
{
	t_uint i = 0, j = 0, bytes = max_bytes(st_arr, n);
	while (i < bytes)
	{
		ft_putnbr_fd(1, i);
		j = 0;
		while (j++ < 8 - countdigits(i))
			write(1, " ", 1);
		j = 0;
		while (j < n)
		{
			if (i < st_arr[j].size * st_arr[j]._type)
			{
				if ((i / st_arr[j]._type) % 2 == 0)
					write(1, "\033[48;5;7;30m", 12);
				else
					write(1, "\033[38;5;7;40m", 12);
				ft_putmem_fd(1, &st_arr[j].data[i], 1, "");
				write(1, "\033[m", 3);
			}
			else
				write(1, "        ", 8);
			j++;
			if (j != n)
				write(1, " ", 1);
		}
		i++;
		write(1, "\n", 1);
	}
}
void	putheader(t_stack *st_arr, t_uint n)
{
	t_uint i = 0, j = 0;

	write(1, "  ", 2);
	while (i < n)
	{
		write(1, "      ST", 8);
		ft_putnbr_fd(1, i++);
	}
	i = 0;
	write(1, "\ncap  =  ", 9);
	while (i < n)
	{
		ft_putnbr_fd(1, st_arr[i].cap);
		j = 0;
		while (j++ < 9 - countdigits(st_arr[i].cap))
			write(1, " ", 1);
		i++;
	}
	i = 0;
	write(1, "\nsize =  ", 9);
	while (i < n)
	{
		ft_putnbr_fd(1, st_arr[i].size);
		j = 0;
		while (j++ < 9 - countdigits(st_arr[i].cap))
			write(1, " ", 1);
		i++;
	}
	write(1, "\n\n", 2);
}

int main(void)
{
	t_stack	st_arr[6]={{0, 0, 0, 0, 0}, {0}};
	t_uint i = 0, j = 0;

	short	data0[] = {16705, 16705, 16705, 16705, 16705, 16705, 16705};
	t_uint	data1[] = {3765450780, 235373505, 3765450780, 235373505, 3765450780};
	double	data2[] = {20.4, 50.9123, 8239.758};
	t_uchar	data3[] = {128, 64, 32, 16, 8, 4, 2, 1, 2, 4, 8, 16};
	t_uchar	data4[]	= {51, 51, 51, 85, 85, 85, 60, 60, 60, 204, 204, 204, 170, 170, 170, 195, 195, 195};
	t_uchar	*data_arr[] = {(t_uchar *)&data0, (t_uchar *)&data1, (t_uchar *)&data2, (t_uchar *)&data3, data4};

	putheader(st_arr, 5);
	ft_stack_init(&st_arr[0], sizeof(data0) / sizeof(*data0), sizeof(*data0));
	ft_stack_init(&st_arr[1], sizeof(data1) / sizeof(*data1), sizeof(*data1));
	ft_stack_init(&st_arr[2], sizeof(data2) / sizeof(*data2), sizeof(*data2));
	ft_stack_init(&st_arr[3], sizeof(data3) / sizeof(*data3), sizeof(*data3));
	ft_stack_init(&st_arr[4], 6, 3);
	while (j < 5)
	{
		i = 0;
		while (i < st_arr[j].cap)
			ft_stack_push(&st_arr[j], &data_arr[j][i++ * st_arr[j]._type]);
		j++;
	}
	putheader(st_arr, 5);
	putdata(st_arr, 5);
}
