#include "include/cub3d.h"

int	is_collision(t_cub *game, double nx, double ny)
{
	if (nx <= 1. || (int)nx > game->size->x_size - 1)
	{
		printf("nx\n");
		return (1);
	}
	if (ny <= 1. || (int)ny > game->size->y_size - 1)
	{
		printf("ny\n");
		return (1);
	}
	if (game->map[(int)nx][(int)ny] == 1)
	{
		printf("map\n");
		return (1);
	}
	else
		return (0);
}

void	move_ws(t_cub *game, int flag)
{
	double	x_move;
	double	y_move;

	x_move = cos(game->player->th) * flag * MOVE_DIST;
	y_move = sin(game->player->th) * flag * MOVE_DIST;
	if (is_collision(game, game->player->x + x_move, game->player->y + y_move))
	{
		printf("Contact wall with move_ws \n");
		return ;
	}
	game->player->x += x_move;
	game->player->y += y_move;
}

void	move_ad(t_cub *game, int flag)
{
	double	x_move;
	double	y_move;

	x_move = sin(game->player->th) * flag * MOVE_DIST;
	y_move = cos(game->player->th) * flag * MOVE_DIST;
	if (is_collision(game, game->player->x + x_move, game->player->y + y_move))
	{
		printf("Contact wall with move_ad \n");
		return ;
	}
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
