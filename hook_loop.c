#include "include/cub3d.h"

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