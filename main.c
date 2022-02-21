#include "include/cub3d.h"

t_cub	*get_cub()
{
	static t_cub	cub;
	static t_size	size;

	cub.size = &size;
	return (&cub);
}

int	arg_check(int argc, char **argv)
{
	if (argc < 2)
		printf("error\n");
	(void)argv;
	return (-1);
}

int	main(int argc, char **argv)
{
	arg_check(argc, argv);
	parsing(argv[1]);
}
