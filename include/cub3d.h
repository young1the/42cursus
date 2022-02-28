#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

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

typedef struct s_size
{
	int		x_size;
	int		y_size;
}			t_size;

typedef struct player
{
	double	x;
	double	y;
	double	th;
}			t_player;

typedef struct				s_img
{
	void					*img;
	char					*data;
	int						bpp;
	int						line_size;
	int						endian;
}							t_img;

typedef struct	s_texture
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			te_height;
	int			te_width;
}				t_texture;

typedef struct s_cub
{
	void		*mlx;
	void		*win;
	t_img		img;
	int			**map;
	char		*config[6];
	t_size		*size;
	t_player	*player;
	t_texture	textures;
}				t_cub;

t_cub	*get_cub();
int		rgb_to_hex(char *str);

// init
void	game_init(t_cub *game);

// loop and hook
int				process_close(void);
int				deal_key(int key_code, t_cub *game);
int 			main_loop(t_cub *game);

# include "../libft/libft.h"
# include "../parsing/parsing.h"
# include "../mlx/mlx.h"
# include "../engine/engine.h"

#endif
