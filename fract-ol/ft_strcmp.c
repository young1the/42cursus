/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: young-ch <young-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 14:47:51 by young-ch          #+#    #+#             */
/*   Updated: 2021/06/12 18:12:49 by young-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*t1;
	unsigned char	*t2;

	t1 = (unsigned char*)s1;
	t2 = (unsigned char*)s2;
	while ((*t1 || *t2))
	{
		if (*t1 != *t2)
			return (*t1 - *t2);
		t1++;
		t2++;
	}
	return (0);
}
