#include "../include/cub3d.h"

#include <math.h>
#include <stdio.h>
#define  EPS (1e-06) // 'IEEE 754','machine epsilon'

int	is_zero(double d)
{
	if (fabs(d) < EPS)
		return (1);
	else
		return (0);
}

double	deg_to_rad(double deg)
{
	double	rad;

	rad = (deg)*M_PI/180.0;
	return (rad);
}

double	rad_to_deg(double rad)
{
	double	deg;

	deg = (rad)*180.0/M_PI;
	return (deg);
}

int	map_get_cell(int x, int y)
{
	t_cub	*cub;

	cub = get_cub();
	if (x >= 0 && x < cub->size->x_size && y >=0 && y < cub->size->y_size)
		return (cub->map[x][y]);
	else
		return (-1);
}

int	get_sign( double d )
{
	if (is_zero(d))
		return (0);
	if (d > 0)
		return (1);
	else
		return (-1);
}

double	get_distance(double x0, double y0, double x1, double y1)
{
	double	dx;
	double	dy;
	double	ret;

	dx = x0 - x1;
	dy = y0 - y1;
	ret = sqrt(dx*dx + dy*dy);
	return (ret);
}

double	get_angle_per_pixel(int fov, int sx)
{
	double	ret;
	double	fov_r;

	fov_r = deg_to_rad(fov);
	ret = fov_r / (sx - 1);
	return (ret);
}

typedef struct s_ray
{
	double	wx;
	double	wy;
	int		wdir;
}	t_ray;


void	cast_single_ray(t_ray *ray, int i)
{
	t_cub	*cub;
	double	ray_r;

	ray_r = (cub->player->th + fov_h / 2) - (i * get_angle_per_pixel());
	get_wall_intersection(ray, ray_r);
}

void	ray_casting()
{
	int		i;
	double	distance;
	t_ray	ray;

	i = 0;
	int sx = 720;
	while (i < sx)
	{
		cast_single_ray(&ray, i);
		// draw_wall(&ray);
		i++;
	}
}

int main()
{
	printf("90 = %f\n", deg_to_rad(90.0));
	printf("90 = %f\n", rad_to_deg(1.57));

	double d = 0.000007;
	if (is_zero(d))
		printf("is zero\n");
}
