/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: young-ch <young-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:59:35 by young-ch          #+#    #+#             */
/*   Updated: 2021/06/12 18:48:33 by young-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		my_mlx_key_press(int keycode)
{
	if (keycode == KEY_ESC)
	{
		exit(0);
	}
	return (0);
}

int		my_mlx_exit_button(void)
{
	exit(0);
}

void	my_mlx_pixel_put(t_fractol *fractol, int x, int y, int color)
{
	char	*dst;

	dst = fractol->img.data +
	(y * fractol->img.line_size + x * (fractol->img.bpp / 8));
	*(unsigned int*)dst = color;
}

int		my_mlx_mouse_hook(int keycode, int x, int y, t_fractol *fractol)
{
	if (keycode == 5)
	{
		fractol->imaginary_max /= 1.1;
		fractol->imaginary_min /= 1.1;
		fractol->real_max /= 1.1;
		fractol->real_min /= 1.1;
	}
	if (keycode == 4)
	{
		fractol->imaginary_max *= 1.1;
		fractol->imaginary_min *= 1.1;
		fractol->real_max *= 1.1;
		fractol->real_min *= 1.1;
	}
	x = 0;
	y = 0;
	return (0);
}
