#ifndef CUBSTRUCT_H
# define CUBSTRUCT_H

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

typedef struct s_img
{
	void	*img;
	char	*data;
	int		bpp;
	int		line_size;
	int		endian;
}			t_img;

typedef struct s_texture
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		te_height;
	int		te_width;
}			t_texture;

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

t_cub	*get_cub(void);

#endif