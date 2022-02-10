#include "../include/minishell.h"

int	ft_pwd(void)
{
	char	*str;

	str = getcwd(NULL, 1024);
	printf("%s\n", str);
	free (str);
	return (0);
}
