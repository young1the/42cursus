#include "include/cub3d.h"

t_cub	*get_cub(void)
{
	static t_cub	cub;
	static t_size	size;
	static t_player	player;

	cub.size = &size;
	cub.player = &player;
	return (&cub);
}

static int	main_loop(t_cub *game)
{
	static int	image;

	if (image != 0)
	{
		mlx_destroy_image(game->mlx, game->img.img);
		image = 0;
	}
	ray_casting();
	image++;
	return (0);
}

static int	xpm_init(t_cub *game)
{
	game->textures.no = mlx_xpm_file_to_image(game->mlx, game->config[NO],
			&game->textures.te_width, &game->textures.te_height);
	game->textures.so = mlx_xpm_file_to_image(game->mlx, game->config[SO],
			&game->textures.te_width, &game->textures.te_height);
	game->textures.we = mlx_xpm_file_to_image(game->mlx, game->config[WE],
			&game->textures.te_width, &game->textures.te_height);
	game->textures.ea = mlx_xpm_file_to_image(game->mlx, game->config[EA],
			&game->textures.te_width, &game->textures.te_height);
	if (game->textures.no == NULL || game->textures.so == NULL
		|| game->textures.we == NULL || game->textures.ea == NULL)
	{
		ft_error("Error! invalid texture file!\n");
		return (FAILURE);
	}
	return (SUCCESS);
}

static int	game_init(void)
{
	t_cub	*game;

	game = get_cub();
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, W_WIDTH, W_HEIGHT, "./cub3D");
	if (xpm_init(game) == FAILURE)
		return (FAILURE);
	mlx_hook(game->win, X_EVENT_KEY_PRESS, 0, &deal_key, game);
	mlx_hook(game->win, X_EVENT_KEY_EXIT, 0, &process_close, game);
	mlx_loop_hook(game->mlx, &main_loop, game);
	mlx_loop(game->mlx);
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_error("Error!\n");
		return (FAILURE);
	}
	if (parsing(argv[1]) == FAILURE)
		return (FAILURE);
	if (game_init() == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
