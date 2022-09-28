#include "../include/minishell.h"

int	ft_envcmp(const char *str, const char *env_str)
{
	unsigned char	*t1;
	unsigned char	*t2;

	t1 = (unsigned char *)str;
	t2 = (unsigned char *)env_str;
	while (*t1 == *t2)
	{
		t1++;
		t2++;
		if (*t1 == '\0')
			return (0);
	}
	return (*t2 - *t1);
}
