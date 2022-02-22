#include "include/cub3d.h"

void    game_init(t_cub *game)
{
    game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, W_HEIGHT, W_WIDTH, "./cub3D");
	game->img.img = mlx_new_image(game->mlx, W_HEIGHT, W_WIDTH);
	game->img.data = mlx_get_data_addr(game->img.img,
	&(game->img.bpp), &(game->img.line_size), &(game->img.endian));

	game->textures.no = mlx_xpm_file_to_image(game->mlx, game->config[NO], &game->textures.te_width, &game->textures.te_height);
	game->textures.so = mlx_xpm_file_to_image(game->mlx, game->config[SO], &game->textures.te_width, &game->textures.te_height);
	game->textures.we = mlx_xpm_file_to_image(game->mlx, game->config[WE], &game->textures.te_width, &game->textures.te_height);
	game->textures.ea = mlx_xpm_file_to_image(game->mlx, game->config[EA], &game->textures.te_width, &game->textures.te_height);
}