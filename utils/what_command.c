#include "../include/minishell.h"

int	is_builtin(char **cmd)
{
	if (!ft_strcmp("cd", cmd[0]))
		return (1);
	else if (!ft_strcmp("echo", cmd[0]))
		return (1);
	else if (!ft_strcmp("env", cmd[0]))
		return (1);
	else if (!ft_strcmp("export", cmd[0]))
		return (1);
	else if (!ft_strcmp("pwd", cmd[0]))
		return (1);
	else if (!ft_strcmp("unset", cmd[0]))
		return (1);
	else if (!ft_strcmp("exit", cmd[0]))
		return (1);
	else
		return (0);
}

int	is_binary(char **cmd)
{
	char	*filename;

	if (is_absolute_path(cmd))
		filename = ft_strdup(cmd[0]);
	else
		filename = get_filename(cmd);
	if (filename == NULL)
		return (0);
	else
	{
		free(filename);
		return (1);
	}
}
