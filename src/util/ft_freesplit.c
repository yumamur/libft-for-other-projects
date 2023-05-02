#include "libft.h"

void	ft_freesplit(char *arr[])
{
	char	*pt;

	pt = *arr;
	while (pt)
	{
		free(pt);
		pt++;
	}
	free(arr);
	arr = NULL;
}
