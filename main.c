#include "include/cub3d.h"

t_cub	*get_cub()
{
	static t_cub	cub;
	static t_size	size;
	static t_player	player;

	cub.size = &size;
	cub.player = &player;
	return (&cub);
}

int	arg_check(int argc, char **argv)
{
	if (argc < 2)
		printf("Error!\n");
	(void)argv;
	return (-1);
}

int	main(int argc, char **argv)
{
	t_cub *game;

	arg_check(argc, argv);
	parsing(argv[1]);

	// init
	game = get_cub();
	game_init(game);
	// loop
	mlx_hook(game->win, X_EVENT_KEY_PRESS, 0, &deal_key, game);
	mlx_hook(game->win, X_EVENT_KEY_EXIT, 0, &process_close, game);
	mlx_loop_hook(game->mlx, &main_loop, game);
	mlx_loop(game->mlx);
}
