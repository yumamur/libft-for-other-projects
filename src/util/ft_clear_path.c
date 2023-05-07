#include "libft.h"

void	ft_clear_path(char **path)
{
	char	*tmp;

	tmp = ft_strdup(ft_strrchr(*path, '/') + 1);
	free(*path);
	*path = ft_strdup(tmp);
	free(tmp);
}
