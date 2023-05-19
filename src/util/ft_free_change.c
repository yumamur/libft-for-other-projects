#include "../../include/libft.h"

void	ft_free_change(void *dest, void *src)
{
	if (dest)
		free(dest);
	dest = src;
}
