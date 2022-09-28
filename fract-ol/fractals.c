/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: young-ch <young-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:43:24 by young-ch          #+#    #+#             */
/*   Updated: 2021/06/12 18:44:08 by young-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		draw_fractal(t_fractol *fractol)
{
	t_complex	complex;

	fractol->real_range = fractol->real_max - fractol->real_min;
	fractol->imaginary_range = fractol->imaginary_max - fractol->imaginary_min;
	if (fractol->menu == 1)
	{
		complex.real = 0;
		complex.imaginary = 0;
		mandelbrot(fractol, complex);
	}
	if (fractol->menu == 2)
	{
		complex.real = JULIA_REAL;
		complex.imaginary = JULIA_IMAGINARY;
		julia(fractol, complex);
	}
	if (fractol->menu == 3)
	{
		complex.real = 0;
		complex.imaginary = 0;
		burningship(fractol, complex);
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
	return (0);
}

void	mandelbrot(t_fractol *fractol, t_complex z)
{
	int			x;
	int			y;
	t_complex	c;
	double		temp;
	int			iteration;

	x = 0;
	while (x++ < WIDTH)
	{
		y = 0;
		while (y++ < HEIGHT)
		{
			xy_to_complex(fractol, &c, x, y);
			make_zero_complex(&z);
			iteration = 0;
			while (iteration++ < MAX_ITERATION && check_divergence(&z))
			{
				temp = z.real * z.real - z.imaginary * z.imaginary + c.real;
				z.imaginary = 2 * z.real * z.imaginary + c.imaginary;
				z.real = temp;
			}
			iteration >= MAX_ITERATION ? my_mlx_pixel_put(fractol, x, y, 0) :
			my_mlx_pixel_put(fractol, x, y, iteration * BLUE_COLOR);
		}
	}
}

void	julia(t_fractol *fractol, t_complex c)
{
	int			x;
	int			y;
	t_complex	z;
	double		temp;
	int			iteration;

	x = 0;
	while (x++ < WIDTH)
	{
		y = 0;
		while (y++ < HEIGHT)
		{
			iteration = 0;
			xy_to_complex(fractol, &z, x, y);
			while (iteration++ < MAX_ITERATION && check_divergence(&z))
			{
				temp = z.real * z.real - z.imaginary * z.imaginary + c.real;
				z.imaginary = 2 * z.real * z.imaginary + c.imaginary;
				z.real = temp;
			}
			iteration >= MAX_ITERATION ? my_mlx_pixel_put(fractol, x, y, 0) :
			my_mlx_pixel_put(fractol, x, y, iteration * BLUE_COLOR);
		}
	}
}

void	burningship(t_fractol *fractol, t_complex z)
{
	int			x;
	int			y;
	t_complex	c;
	double		temp;
	int			iteration;

	x = 0;
	while (x++ < WIDTH)
	{
		y = 0;
		while (y++ < HEIGHT)
		{
			xy_to_complex(fractol, &c, x, y);
			make_zero_complex(&z);
			iteration = 0;
			while (iteration++ < MAX_ITERATION && check_divergence(&z))
			{
				temp = z.real * z.real - z.imaginary * z.imaginary + c.real;
				z.imaginary = fabs(2 * z.real * z.imaginary) + c.imaginary;
				z.real = temp;
			}
			iteration >= MAX_ITERATION ? my_mlx_pixel_put(fractol, x, y, 0) :
			my_mlx_pixel_put(fractol, x, y, iteration * RED_COLOR);
		}
	}
}
