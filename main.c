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
		printf("error\n");
	(void)argv;
	return (-1);
}

int	deal_key(int key_code, t_cub *game)
{
	(void)game;
	if (key_code == KEY_W)
		printf("KEY W\n");
	else if (key_code == KEY_A)
		printf("KEY A\n");
	else if (key_code == KEY_S)
		printf("KEY S\n");
	else if (key_code == KEY_D)
		printf("KEY D\n");
	else if (key_code == KEY_LEFT_ARROW)
		printf("KEY LEFT\n");
	else if (key_code == KEY_RIGHT_ARROW)
		printf("KEY RIGHT\n");
	else if (key_code == KEY_ESC)
	{
		printf("KEY_PRESS");
		exit(0);
	}
	return (0);
}

int				process_close(void)
{
	printf("KEY_EXIT");
	exit(0);
}

int main_loop(t_cub *game)
{
	(void)game;
	return (0);
}

int	main(int argc, char **argv)
{
	t_cub *game;
	arg_check(argc, argv);
	parsing(argv[1]);

	// init
	game = get_cub();
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, W_HEIGHT, W_WIDTH, "./cub3D");
	game->img.img = mlx_new_image(game->mlx, W_HEIGHT, W_WIDTH);
	game->img.data = mlx_get_data_addr(game->img.img,
	&(game->img.bpp), &(game->img.line_size), &(game->img.endian));

	ray_casting();
	// loop
	mlx_hook(game->win, X_EVENT_KEY_PRESS, 0, &deal_key, &game);
	mlx_hook(game->win, X_EVENT_KEY_EXIT, 0, &process_close, &game);
	mlx_loop_hook(game->mlx, &main_loop, &game);
	mlx_loop(game->mlx);
}
