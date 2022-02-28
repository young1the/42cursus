#include "engine.h"

static int	is_collision(t_cub *game, double nx, double ny)
{
	if (nx <= 1. || (int)nx > game->size->x_size - 1)
		return (1);
	if (ny <= 1. || (int)ny > game->size->y_size - 1)
		return (1);
	if (map_get_cell((int)nx, (int)ny) == 1)
		return (1);
	else
		return (0);
}

static void	move_ws(t_cub *game, int flag)
{
	double	x_move;
	double	y_move;

	x_move = cos(game->player->th) * flag * MOVE_DIST;
	y_move = sin(game->player->th) * flag * MOVE_DIST;
	if (is_collision(game, game->player->x + x_move, game->player->y + y_move))
		return ;
	game->player->x += x_move;
	game->player->y += y_move;
}

static void	move_ad(t_cub *game, int flag)
{
	double	x_move;
	double	y_move;

	x_move = sin(game->player->th) * flag * MOVE_DIST;
	y_move = cos(game->player->th) * flag * MOVE_DIST;
	if (is_collision(game, game->player->x - x_move, game->player->y + y_move))
		return ;
	game->player->x -= x_move;
	game->player->y += y_move;
}

int	deal_key(int key_code, t_cub *game)
{
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
		printf("Exit\n");
		exit(0);
	}
	return (0);
}

int	process_close(void)
{
	printf("Exit\n");
	exit(0);
}
