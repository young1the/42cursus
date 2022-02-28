#include "engine.h"

static int	get_wall_height(t_wall *wall)
{
	double	fov_h;
	double	fov_v;
	double	fov;

	fov_h = deg_to_rad(FOV_H);
	fov_v = fov_h*(double)W_WIDTH/(double)W_HEIGHT;
	fov = 2.0 * wall->dist * tan(fov_v/2.0);
	return ((int)(W_HEIGHT * 1 / fov));
}

void	draw_wall(t_wall *wall, int x)
{
	int		wh;
	t_cub	*cub;
	int		color;
	int		y_start;
	int		y_end;

	cub = get_cub();
	wh = get_wall_height(wall);
	y_start = (W_HEIGHT - wh) / 2;
	y_end = y_start + wh;
	y_start = max(0, y_start);
	y_end = min(W_HEIGHT - 1, y_end);
	while (y_end >= y_start)
	{
		color = get_color(wall, wh, (y_end - y_start));
		my_mlx_pixel_put(cub, x, y_end, color);
		y_end--;
	}
}

void	draw_floorceil(t_cub *cub)
{
	int		color;
	int		x;
	int		y;

	y = 0;
	while (y < W_HEIGHT)
	{
		if (y < W_HEIGHT/2)
			color = rgb_to_hex(cub->config[C]);
		else
			color = rgb_to_hex(cub->config[F]);
		x = 0;
		while (x < W_WIDTH)
		{
			my_mlx_pixel_put(cub, x, y, color);
			x++;
		}
		y++;
	}
}
