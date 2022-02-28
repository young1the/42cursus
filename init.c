#include "include/cub3d.h"

void	game_init(t_cub *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, W_WIDTH, W_HEIGHT, "./cub3D");
	game->textures.no = mlx_xpm_file_to_image(game->mlx, game->config[NO], &game->textures.te_width, &game->textures.te_height);
	game->textures.so = mlx_xpm_file_to_image(game->mlx, game->config[SO], &game->textures.te_width, &game->textures.te_height);
	game->textures.we = mlx_xpm_file_to_image(game->mlx, game->config[WE], &game->textures.te_width, &game->textures.te_height);
	game->textures.ea = mlx_xpm_file_to_image(game->mlx, game->config[EA], &game->textures.te_width, &game->textures.te_height);
}
