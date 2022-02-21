#include "libft.h"

char	*ft_strndup(const char *s1, int n)
{
	char	*dup;
	char	*ret;
	int		i;

	if (s1 == NULL)
		return (NULL);
	i = ft_strlen(s1);
	if (n > i || n <= 0)
		return (NULL);
	dup = (char *)malloc(sizeof(char) * (n + 1));
	if (dup == NULL)
		return (NULL);
	ret = dup;
	while (n--)
		*dup++ = *s1++;
	*dup = 0;
	return (ret);
}
