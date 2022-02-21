#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*s_p;

	s_p = (unsigned char*)s;
	while (len-- > 0)
	{
		*s_p = (unsigned char)c;
		s_p++;
	}
	return (s);
}
