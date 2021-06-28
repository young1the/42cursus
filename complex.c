/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: young-ch <young-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 17:46:55 by young-ch          #+#    #+#             */
/*   Updated: 2021/06/12 18:06:50 by young-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	xy_to_complex(t_fractol *fractol, t_complex *c, int x, int y)
{
	c->real = fractol->real_min + (fractol->real_range / WIDTH * x);
	c->imaginary = fractol->imaginary_min +
	(fractol->imaginary_range / HEIGHT * y);
}

void	make_zero_complex(t_complex *c)
{
	c->real = 0;
	c->imaginary = 0;
}

int		check_divergence(t_complex *c)
{
	if (c->real * c->real + c->imaginary * c->imaginary > 4 * 4)
		return (0);
	return (1);
}
