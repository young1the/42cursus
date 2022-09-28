#include "../include/minishell.h"

static size_t	count_string(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
			{
				i++;
			}
		}
		else
			i++;
	}
	return (count);
}

static size_t	count_string_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	char	*s_tmp;
	size_t	i;
	size_t	j;

	ret = (char **)malloc(sizeof(char *) * (count_string(s, c) + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	s_tmp = (char *)s;
	while (*s_tmp)
	{
		if (*s_tmp != c)
		{
			j = count_string_len(s_tmp, c);
			ret[i] = (char *)malloc(sizeof(char) * (j + 1));
			ft_strlcpy(ret[i++], s_tmp, j + 1);
			s_tmp += j;
		}
		else
			s_tmp++;
	}
	ret[i] = NULL;
	return (ret);
}
