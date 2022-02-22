#ifndef ENGINE_H
# define ENGINE_H

# include "../include/cub3d.h"

#define EPS (1e-06) // 'IEEE 754','machine epsilon'

int	is_zero(double d);
double	deg_to_rad(double deg);
double	rad_to_deg(double rad);
int	get_sign(double d);
double	get_distance(double x0, double y0, double x1, double y1);

void	ray_casting();

#endif
