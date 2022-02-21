#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# define SUCCESS 0
# define FAILURE 1
# define NULL_SPACE 9

typedef struct s_size
{
	int		x_size;
	int		y_size;
}			t_size;

typedef struct s_cub
{
	int			**map;
	char		*config[6];
	t_size		*size;
}				t_cub;

t_cub	*get_cub();

# include "../libft/libft.h"
# include "../parsing/parsing.h"

#endif
