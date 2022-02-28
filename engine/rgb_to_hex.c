#include "engine.h"

static void	free_argv(char **datas)
{
	int		i;

	i = 0;
	if (datas == NULL)
		return ;
	while (datas[i] != NULL)
	{
		free (datas[i]);
		i++;
	}
	free(datas);
}

static int	get_hex(char **split)
{
	int		r;
	int		g;
	int		b;
	int		hex;

	hex = 0;
	r = ft_atoi(split[0]);
	g = ft_atoi(split[1]);
	b = ft_atoi(split[2]);
	if (r > 255 || g > 255 || b > 255 || r < 0 || g < 0 || b < 0)
	{
		printf("Error! R,G,B colors in range [0,255]\n");
		return (-1);
	}
	hex = (r << 16 | g << 8 | b);
	return (hex);
}

int	rgb_to_hex(char *str)
{
	char	**split;
	int		i;
	int		hex;

	split = ft_split(str, ',');
	i = 0;
	while (split[i] != NULL)
		i++;
	if (i != 3)
	{
		printf("ERROR! information must be [R,G,B]\n");
		free_argv(split);
		return (-1);
	}
	hex = get_hex(split);
	free_argv(split);
	return (hex);
}
