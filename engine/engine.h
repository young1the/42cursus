#ifndef ENGINE_H
# define ENGINE_H

# include "../include/cub3d.h"

#define EPS (1e-06) // 'IEEE 754','machine epsilon'

typedef struct s_wall
{
	double	x;
	double	y;
	int		dir;
	double	dist;
}			t_wall;

/* math */
int		is_zero(double d);
double	deg_to_rad(double deg);
double	rad_to_deg(double rad);
int		get_sign(double d);
double	get_distance(double x0, double y0, double x1, double y1);
int		min(int a, int b);
int		max(int a, int b);
/* math */

/* draw */
int		rgb_to_hex(char *str);
void	my_mlx_pixel_put(t_cub *cub, int x, int y, int color);
int		get_pixel_color(char *texture, int x, int y);
int		get_color(t_wall *wall, int wh, double y);
void	draw_floorceil(t_cub *cub);
void	draw_wall(t_wall *wall, int x);

/* raycasting */
int		map_get_cell(int x, int y);
double	get_angle_per_pixel();
void	copy_wall(t_wall *origin, t_wall *copy);
void	ray_casting();

#endif
