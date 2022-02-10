#include "../include/minishell.h"

static void	change_oldpwd(char *str)
{
	char	*oldpwd;
	char	*temp;
	int		i;

	oldpwd = ft_strjoin("OLDPWD=", str);
	i = 0;
	while (g_mini.envs[i] != NULL)
	{
		if (!ft_envcmp("OLDPWD", g_mini.envs[i]))
			break ;
		i++;
	}
	temp = g_mini.envs[i];
	g_mini.envs[i] = oldpwd;
	free (temp);
}

static char	*get_dollar_home(char *cmd1)
{
	char	*dollar_home;
	int		cmd_len;

	cmd_len = ft_strlen(cmd1);
	dollar_home = (char *)malloc(sizeof(char) * (cmd_len + 1));
	*dollar_home = '$';
	ft_strlcpy(dollar_home + 1, cmd1, cmd_len);
	return (dollar_home);
}

static char	*find_home(char *cmd1)
{
	char	*dollar_home;
	char	*target;
	char	*home_dir;

	home_dir = find_value(g_mini.envs, "HOME");
	dollar_home = get_dollar_home(cmd1);
	target = change_string(dollar_home, "~", home_dir);
	free(dollar_home);
	return (target);
}

static char	*get_target(char **cmd)
{
	char	*target;

	if (cmd[1] == NULL)
		return (NULL);
	if (cmd[1][0] == '~')
		target = find_home(cmd[1]);
	else
		target = ft_strdup(cmd[1]);
	return (target);
}

int	ft_cd(char **cmd)
{
	int		exit_num;
	char	*target;
	char	*oldpwd;

	target = get_target(cmd);
	if (target == NULL)
		return (0);
	oldpwd = getcwd(NULL, 1024);
	exit_num = chdir(target);
	free(target);
	if (exit_num != 0)
	{
		free(oldpwd);
		ft_error("minishell : cd : no such file or directory : ");
		ft_error(cmd[1]);
		ft_error("\n");
		return (NO_FILE);
	}
	else
	{
		change_oldpwd(oldpwd);
		free (oldpwd);
		return (0);
	}
}
