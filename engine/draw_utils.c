#include "engine.h"

void	my_mlx_pixel_put(t_cub *cub, int x, int y, int color)
{
	char	*dst;

	dst = cub->img.data +
	(y * cub->img.line_size + x * (cub->img.bpp / 8));
	*(unsigned int*)dst = color;
}

int		get_pixel_color(char *texture, int x, int y)
{
	t_img			img;
	unsigned char	bit;
	char			*dst;
	unsigned int	color;

	bit = 0b11111111;
	img.img = texture;
	img.data = mlx_get_data_addr(img.img, &(img.bpp), &(img.line_size), &(img.endian));
	color = 0;
	dst = (img.data + (y * img.line_size + x * (img.bpp / 8)));
	color += *dst & bit;
	dst++;
	color += (*dst & bit) << 8;
	dst++;
	color += (*dst & bit) << 16;
	return (color);
}

int		get_color(t_wall *wall, int wh, double y)
{
	t_cub	*cub;
	int		pixel_x;
	int		pixel_y;

	cub = get_cub();
	if (wall->dir == W)
		pixel_x = 64 * (wall->y - floor(wall->y));
	else if (wall->dir == E)
		pixel_x =  64 * (ceil(wall->y) - (wall->y));
	else if (wall->dir == N)
		pixel_x = 64 * (ceil(wall->x) - (wall->x));
	else
		pixel_x = 64 * (wall->x - floor(wall->x));
	pixel_y = 64 * y / wh;
	if (wall->dir == N)
		return (get_pixel_color(cub->textures.no, pixel_x, pixel_y));
	else if (wall->dir == S)
		return (get_pixel_color(cub->textures.so, pixel_x, pixel_y));
	else if (wall->dir == E)
		return (get_pixel_color(cub->textures.ea, pixel_x, pixel_y));
	else if (wall->dir == W)
		return (get_pixel_color(cub->textures.we, pixel_x, pixel_y));
	else
		return (0);
}
