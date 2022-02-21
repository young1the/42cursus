#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# define SUCCESS 0
# define FAILURE 1
# define NULL_SPACE 9
# define W_HEIGHT 500
# define W_WIDTH 500
# define FOV 60

// Define value of Key
# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_EXIT	17
# define KEY_ESC			53
# define KEY_W				13
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define KEY_LEFT_ARROW		123
# define KEY_RIGHT_ARROW	124

typedef struct s_size
{
	int		x_size;
	int		y_size;
}			t_size;

typedef struct s_cub
{
	void		*mlx;
	void		*win;
	int			**map;
	char		*config[6];
	t_size		*size;
}				t_cub;

t_cub	*get_cub();
int		rgb_to_hex(char *str);

# include "../libft/libft.h"
# include "../parsing/parsing.h"
# include "../mlx/mlx.h"

#endif
