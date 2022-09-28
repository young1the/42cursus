#include "../include/minishell.h"

static void	fill_unset_datas(char **cmd, char **valid_datas)
{
	int		count;
	int		i;
	int		j;

	count = 0;
	i = 1;
	while (cmd[i] != NULL)
	{
		j = 0;
		while (cmd[i][j] != '\0')
		{
			if (ft_isalpha(cmd[i][j]) == FALSE)
				break ;
			j++;
		}
		if (cmd[i][j] == '\0')
		{
			valid_datas[count] = ft_strdup(cmd[i]);
			count++;
		}
		else
			valid_data_error(cmd, i);
		i++;
	}
	valid_datas[count] = NULL;
}

static int	get_unset_count(char **cmd)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (cmd[i] != NULL)
	{
		j = 0;
		while (cmd[i][j] != '\0')
		{
			if (ft_isalpha(cmd[i][j]) == FALSE)
				break ;
			j++;
		}
		if (cmd[i][j] == '\0')
			count++;
		i++;
	}
	return (count);
}

char	**make_unsetvalid_datas(char **cmd)
{
	char	**valid_datas;
	int		count;

	count = get_unset_count(cmd);
	if (count == 0)
		return (NULL);
	valid_datas = (char **)malloc(sizeof(char *) * (count + 1));
	if (valid_datas == NULL)
		return (NULL);
	fill_unset_datas(cmd, valid_datas);
	return (valid_datas);
}
