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

typedef struct s_wall
{
	double	x;
	double	y;
	int		dir;
	double	dist;
}			t_wall;

int	hit(t_wall *wall, double x, double y, int dir)
{
	t_cub	*cub;

	cub = get_cub();
	wall->x = x;
	wall->y = y;
	wall->dir = dir;
	wall->dist = get_distance(cub->player->x, cub->player->y, x, y);
	return (SUCCESS);
}

int	cast_y(t_cub *cub, t_wall *wall, double ray)
{
	int		step;
	double	slope;
	double	x;
	double	y;

	wall->dist = 0;
	step = get_sign(sin(ray));
	if (step == 0)
		return (FAILURE);
	slope = 1./tan(ray);
	if (step > 0)
		y = floor(cub->player->y + 1);
	else
		y = ceil(cub->player->y - 1);
	while (y >= 0 && y < cub->size->y_size)
	{
		x = slope * (y- cub->player->y) + cub->player->x;
		if (step > 0)
		{
			if (map_get_cell((int)x, (int)y) == 1)
				return (hit(wall, x, y, S));
		}
		else
		{
			if (map_get_cell((int)x, (int)(y - 1)) == 1)
				return (hit(wall, x, y, N));
		}
		y += step;
	}
	return (FAILURE);
}

int	cast_x(t_cub *cub, t_wall *wall, double ray)
{
	int		step;
	double	slope;
	double	x;
	double	y;

	wall->dist = 0;
	step = get_sign(cos(ray));
	if (step == 0)
		return (FAILURE);
	slope = tan(ray);
	if (step > 0)
		x = floor(cub->player->x + 1);
	else
		x = ceil(cub->player->x - 1);
	while (x >= 0 && x < cub->size->x_size)
	{
		y = slope * (x - cub->player->x) + cub->player->y;
		if (step > 0)
		{
			if (map_get_cell((int)x, (int)y) == 1)
				return (hit(wall, x, y, E));
		}
		else
		{
			if (map_get_cell((int)(x - 1), (int)y) == 1)
				return (hit(wall, x, y, W));
		}
		x += step;
	}
	return (FAILURE);
}

void	copy_wall(t_wall *origin, t_wall *copy)
{
	copy->x = origin->x;
	copy->y = origin->y;
	copy->dir = origin->dir;
	copy->dist = origin->dist;
}

double	cast_single_ray(t_wall *wall, int x)
{
	t_cub	*cub;
	double	ray;
	t_wall	wall_x;
	t_wall	wall_y;

	cub = get_cub();
	ray = (cub->player->th + deg_to_rad(FOV_H) / 2) - get_angle_per_pixel() * x;
	cast_x(cub, &wall_x, ray);
	cast_y(cub, &wall_y, ray);
	if (wall_x.dist == 0)
	{
		copy_wall(&wall_y, wall);
		return (ray);
	}
	if (wall_y.dist == 0)
	{
		copy_wall(&wall_x, wall);
		return (ray);
	}
	if (wall_x.dist > wall_y.dist)
		copy_wall(&wall_y, wall);
	else
		copy_wall(&wall_x, wall);
	return (ray);
}

int	get_wall_height(t_wall *wall)
{
	double	fov_h;
	double	fov_v;
	double	fov;

	fov_h = deg_to_rad(FOV_H);
	fov_v = fov_h*(double)W_WIDTH/(double)W_HEIGHT;
	fov = 2.0 * wall->dist * tan(fov_v/2.0);
	return ((int)(W_HEIGHT * 1 / fov));
}

int		get_color(t_wall *wall)
{
	if (wall->dir == N)
		return (0xAAA939);
	else if (wall->dir == S)
		return (0x7D9F35);
	else if (wall->dir == E)
		return (0x872D62);
	else if (wall->dir == W)
		return (0x572A72);
	else
		return (0);
}

void	draw_wall(t_wall *wall, int x)
{
	int		wh;
	t_cub	*cub;
	int		color;

	cub = get_cub();
	wh = get_wall_height(wall);
	int		y_start;
	int		y_end;
	y_start = (W_HEIGHT - wh) / 2;
	y_end = y_start + wh;
	y_start = max(0, y_start);
	y_end = min(W_HEIGHT - 1, y_end);
	color = get_color(wall);
	while (y_start < y_end)
	{
		my_mlx_pixel_put(cub, x, y_start, color);
		y_start++;
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

void	ray_casting()
{
	int		x;
	double	sup;
	t_wall	wall;
	t_cub	*cub;

	x = 0;
	cub = get_cub();
	cub->img.img = mlx_new_image(cub->mlx, W_WIDTH, W_HEIGHT);
	cub->img.data = mlx_get_data_addr(cub->img.img,
	&(cub->img.bpp), &(cub->img.line_size), &(cub->img.endian));
	draw_floorceil(cub);
	while (x < W_WIDTH)
	{
		sup = cast_single_ray(&wall, x);
		wall.dist *= cos(cub->player->th - sup);
		draw_wall(&wall, x);
		x++;
	}
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img.img, 0, 0);
	return ;
}
