#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# include "./cubstruct.h"
# include "../libft/libft.h"
# include "../parsing/parsing.h"
# include "../mlx/mlx.h"
# include "../engine/engine.h"

# define SUCCESS 0
# define FAILURE 1
# define W_WIDTH 720
# define W_HEIGHT 480
# define FOV_H 60

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
# define MOVE_DIST 0.2
// map element
# define NULL_SPACE -1
# define EMPTY 0
# define WALL 1
# define N 2
# define S 3
# define W 4
# define E 5

#endif
