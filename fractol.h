/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: young-ch <young-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:02:28 by young-ch          #+#    #+#             */
/*   Updated: 2021/06/12 18:43:41 by young-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./mlx/mlx.h"
# include <stdio.h>
# include <math.h>
# include <stdlib.h>

# define WIDTH				640
# define HEIGHT				480

# define BLUE_COLOR			0x05050A
# define RED_COLOR			0x0A0505

# define JULIA_REAL			-0.835
# define JULIA_IMAGINARY	-0.2321
# define MAX_ITERATION		100

# define KEY_EVENT_PRESS	2
# define KEY_EVENT_EXIT		17

# define MOUSE_UP			4
# define MOUSE_DOWN			5
# define KEY_ESC			53

typedef struct				s_complex
{
	double					real;
	double					imaginary;
}							t_complex;

typedef struct				s_img
{
	void					*img;
	char					*data;
	int						bpp;
	int						line_size;
	int						endian;
}							t_img;

typedef struct				s_fractol
{
	void					*mlx;
	void					*win;
	int						menu;
	t_img					img;
	double					real_min;
	double					real_max;
	double					imaginary_min;
	double					imaginary_max;
	double					real_range;
	double					imaginary_range;
}							t_fractol;

int							my_mlx_key_press(int keycode);
int							my_mlx_exit_button(void);
void						my_mlx_pixel_put
							(t_fractol *fractol, int x, int y, int color);
int							my_mlx_mouse_hook
							(int keycode, int x, int y, t_fractol *fractol);

int							check_argv(char *argv);
int							print_usage(void);
void						give_info(t_fractol *fractol);
void						init_fractol(t_fractol *fractol);
int							main(int argc, char *argv[]);

int							draw_fractal(t_fractol *fractol);
void						mandelbrot(t_fractol *fractol, t_complex z);
void						julia(t_fractol *fractol, t_complex c);
void						burningship(t_fractol *fractol, t_complex z);

void						make_zero_complex(t_complex *c);
void						xy_to_complex
							(t_fractol *fractol, t_complex *c, int x, int y);
int							check_divergence(t_complex *c);

int							ft_strcmp(const char *s1, const char *s2);

#endif
