#include "include/cub3d.h"

void	move_ws(t_cub *game, int flag)
{
	double	x_move;
	double	y_move;

	x_move = cos(game->player->th) * flag * MOVE_DIST;
	y_move = sin(game->player->th) * flag * MOVE_DIST;
	// crrash check
	game->player->x += x_move;
	game->player->y += y_move;
}

void	move_ad(t_cub *game, int flag)
{
	double	x_move;
	double	y_move;

	x_move = sin(game->player->th) * flag * MOVE_DIST;
	y_move = cos(game->player->th) * flag * MOVE_DIST;
	// crrash check
	game->player->x -= x_move;
	game->player->y += y_move;
}

int	deal_key(int key_code, t_cub *game)
{
	(void)game;
	mlx_destroy_image(game->mlx, game->img.img);
	if (key_code == KEY_W)
		move_ws(game, 1);
	else if (key_code == KEY_A)
		move_ad(game, 1);
	else if (key_code == KEY_S)
		move_ws(game, -1);
	else if (key_code == KEY_D)
		move_ad(game, -1);
	else if (key_code == KEY_LEFT_ARROW)
		game->player->th += deg_to_rad(15);
	else if (key_code == KEY_RIGHT_ARROW)
		game->player->th -= deg_to_rad(15);
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
	ray_casting();
	return (0);
}
