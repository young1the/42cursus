#include "include/cub3d.h"

int	deal_key(int key_code, t_cub *game)
{
	(void)game;
	if (key_code == KEY_W)
		game->player->y -= 0.5;
	else if (key_code == KEY_A)
		game->player->x += 0.5;
	else if (key_code == KEY_S)
		game->player->y += 0.5;
	else if (key_code == KEY_D)
		game->player->x -= 0.5;
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
