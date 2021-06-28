/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: young-ch <young-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 16:58:37 by young-ch          #+#    #+#             */
/*   Updated: 2021/06/12 17:30:56 by young-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		check_argv(char *argv)
{
	if (!(ft_strcmp(argv, "mandelbrot")))
		return (1);
	if (!(ft_strcmp(argv, "julia")))
		return (2);
	if (!(ft_strcmp(argv, "burningship")))
		return (3);
	return (0);
}

int		print_usage(void)
{
	printf("**USAGE ERROR**\n");
	printf("USAGE : ./fractol mandelbrot\n");
	printf("USAGE : ./fractol julia\n");
	printf("USAGE : ./fractol burningship\n");
	return (0);
}

void	give_info(t_fractol *fractol)
{
	if (fractol->menu == 1)
	{
		fractol->real_min = -2.0;
		fractol->real_max = 1.0;
		fractol->imaginary_min = -1.0;
		fractol->imaginary_max = 1.0;
	}
	if (fractol->menu == 2)
	{
		fractol->real_min = -2.0;
		fractol->real_max = 2.0;
		fractol->imaginary_min = -1.0;
		fractol->imaginary_max = 1.0;
	}
	if (fractol->menu == 3)
	{
		fractol->real_min = -3.0;
		fractol->real_max = 2.0;
		fractol->imaginary_min = -3.0;
		fractol->imaginary_max = 2.5;
	}
}

void	init_fractol(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	fractol->win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, "Fractol");
	fractol->img.img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	fractol->img.data = mlx_get_data_addr(fractol->img.img,
	&(fractol->img.bpp), &(fractol->img.line_size), &(fractol->img.endian));
	give_info(fractol);
}

int		main(int argc, char *argv[])
{
	t_fractol	fractol;

	if (argc != 2)
		return (print_usage());
	fractol.menu = check_argv(argv[1]);
	if (!fractol.menu)
		return (print_usage());
	init_fractol(&fractol);
	mlx_hook(fractol.win, KEY_EVENT_PRESS, 0, my_mlx_key_press, &fractol);
	mlx_hook(fractol.win, KEY_EVENT_EXIT, 0, my_mlx_exit_button, &fractol);
	mlx_mouse_hook(fractol.win, my_mlx_mouse_hook, &fractol);
	mlx_loop_hook(fractol.mlx, draw_fractal, &fractol);
	mlx_loop(fractol.mlx);
	return (0);
}
