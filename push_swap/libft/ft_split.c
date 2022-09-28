/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: young-ch <young-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 14:49:42 by young-ch          #+#    #+#             */
/*   Updated: 2021/07/07 14:56:51 by young-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

static void	free_ret(char **ret)
{
	size_t	i;

	i = 0;
	while (ret[i])
		free(ret[i]);
	free(ret);
	return ;
}

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
	size_t	i;
	size_t	j;

	ret = (char **)malloc(sizeof(char *) * (count_string(s, c) + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			j = count_string_len(s, c);
			ret[i] = (char *)malloc(sizeof(char) * (j + 1));
			if (!ret[i])
				free_ret(ret);
			ft_strlcpy(ret[i++], s, j + 1);
			s += j;
		}
		else
			s++;
	}
	ret[i] = NULL;
	return (ret);
}
