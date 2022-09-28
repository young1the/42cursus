#include "../include/minishell.h"

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

	target = NULL;
	if (cmd[1] == NULL)
		target = find_value(g_mini.envs, "HOME");
	else if (cmd[1][0] == '~')
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
	oldpwd = getcwd(NULL, 1024);
	exit_num = chdir(target);
	if (exit_num != 0)
	{
		free(target);
		free(oldpwd);
		ft_cd_err(cmd);
		return (NO_FILE);
	}
	else
	{
		change_cdenv(oldpwd, 0);
		oldpwd = getcwd(NULL, 1024);
		change_cdenv(oldpwd, 1);
		free(target);
		free(oldpwd);
		return (0);
	}
}
