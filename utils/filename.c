#include "../include/minishell.h"

int	check_filename(char *filename)
{
	struct stat		buf;
	int				ret;

	ret = stat(filename, &buf);
	return (ret);
}

char	*get_filename(char **cmd)
{
	char	*value;
	char	**paths;
	char	*filename;
	char	*command;
	int		i;

	value = find_value(g_mini.envs, "PATH");
	paths = ft_split(value, ':');
	free (value);
	command = ft_strjoin("/", cmd[0]);
	i = 0;
	while (paths[i] != NULL)
	{
		filename = ft_strjoin(paths[i], command);
		if (!check_filename(filename))
			break ;
		free(filename);
		filename = NULL;
		i++;
	}
	free(paths);
	free(command);
	return (filename);
}
