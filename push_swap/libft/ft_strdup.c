/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: young-ch <young-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 23:11:39 by young-ch          #+#    #+#             */
/*   Updated: 2021/07/07 14:57:40 by young-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	char	*ret;
	size_t	i;

	i = ft_strlen(s1);
	dup = (char *)malloc(sizeof(char) * (i + 1));
	if (!dup)
		return (NULL);
	ret = dup;
	while (i--)
		*dup++ = *s1++;
	*dup = 0;
	return (ret);
}
