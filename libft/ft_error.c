#include "libft.h"

static void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	write(fd, s, ft_strlen(s));
}

void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
}
