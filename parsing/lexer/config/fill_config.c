#include "../../parsing.h"

static t_type	check_identifier(char *iden)
{
	if (ft_strcmp(iden, "NO") == 0)
		return (NO);
	else if (ft_strcmp(iden, "SO") == 0)
		return (SO);
	else if (ft_strcmp(iden, "WE") == 0)
		return (WE);
	else if (ft_strcmp(iden, "EA") == 0)
		return (EA);
	else if (ft_strcmp(iden, "F") == 0)
		return (F);
	else if (ft_strcmp(iden, "C") == 0)
		return (C);
	else
		return (-1);
}

void	fill_config(char *str, int *flag)
{
	t_cub	*cub;
	char	*iden;
	char	*path;
	int		i;
	t_type	type;

	cub = get_cub();
	i = 0;
	while (str[i] != ' ' && str[i] != '\0')
		i++;
	iden = ft_strndup(str, i);
	while (str[i] == ' ')
		i++;
	path = ft_strdup(str + i);
	type = check_identifier(iden);
	free (iden);
	if (type < 0)
	{
		free(path);
		return ;
	}
	cub->config[type] = path;
	flag[type] = ON;
	return ;
}
