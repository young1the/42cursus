#ifndef PARSING_H
# define PARSING_H

# include "../include/cub3d.h"

# define ON 1
# define OFF 0

typedef enum e_type
{
	NO,
	SO,
	WE,
	EA,
	F,
	C,
	MAP
}	t_type;

typedef struct s_list
{
	char			*str;
	t_type			type;
	struct s_list	*next;
}					t_list;

typedef struct s_locate
{
	int		x;
	int		y;
}			t_locate;

/* list */
void	add_list(t_list *list_head, t_list *new);
void	clear_list(t_list *list_head);
t_list	*last_list(t_list *list_head);
t_list	*new_list(char *string);
int	size_list(t_list *list_head);
/* get_next_line */
int			get_next_line(int fd, char **line);
/* lexer */
int	lexer_list(t_list *list_head);
/* map */
int		init_map(t_list *list_ptr);
void	fill_map(t_cub *cub, t_list *list_ptr);
int		check_up(t_cub *cub);
int		check_down(t_cub *cub);
int		check_left(t_cub *cub);
int		check_right(t_cub *cub);
/* parsing */
int	parsing(char *filename);

#endif
