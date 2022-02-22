#include "../include/cub3d.h"

void	my_mlx_pixel_put(t_cub *cub, int x, int y, int color)
{
	char	*dst;

	dst = cub->img.data +
	(y * cub->img.line_size + x * (cub->img.bpp / 8));
	*(unsigned int*)dst = color;
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

static double	get_angle_per_pixel()
{
	double	ret;
	double	fov_h;

	fov_h = deg_to_rad(FOV_H);
	ret = fov_h / (W_WIDTH - 1);
	return (ret);
}

void	ray_casting()
{
	double app;

	app = get_angle_per_pixel();
	app = rad_to_deg(app);
	printf("%f\n", app);
}