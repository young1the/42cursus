#include "../include/minishell.h"

static void	valid_data_error(char **cmd, int index)
{
	ft_error("minishell : ");
	ft_error(cmd[0]);
	ft_error(" : ");
	ft_error(cmd[index]);
	ft_error(" : not a valid identifier\n");
}

static void	fill_datas(char **cmd, char **valid_datas)
{
	int		count;
	int		i;

	count = 0;
	i = 1;
	while (cmd[i] != NULL)
	{
		if (ft_isalpha(cmd[i][0]) == TRUE)
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

char	**make_valid_datas(char **cmd)
{
	char	**valid_datas;
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (cmd[i] != NULL)
	{
		if (ft_isalpha(cmd[i][0]) == TRUE)
			count++;
		i++;
	}
	if (count == 0)
		return (NULL);
	valid_datas = (char **)malloc(sizeof(char *) * (count + 1));
	if (valid_datas == NULL)
		return (NULL);
	fill_datas(cmd, valid_datas);
	return (valid_datas);
}
