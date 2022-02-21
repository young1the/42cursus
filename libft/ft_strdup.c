#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	char	*ret;
	size_t	i;

	i = ft_strlen(s1);
	if (!(dup = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	ret = dup;
	while (i--)
		*dup++ = *s1++;
	*dup = 0;
	return (ret);
}
