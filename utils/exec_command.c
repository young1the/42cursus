#include "../include/minishell.h"

int	is_absolute_path(char **cmd)
{
	int		i;

	i = 0;
	while (cmd[0][i] != '\0')
	{
		if (cmd[0][i] == '/')
			return (1);
		i++;
	}
	return (0);
}

static int	exec_bin(char **cmd)
{
	char	*filename;
	pid_t	pid;
	int		i;

	i = 0;
	if (is_absolute_path(cmd))
		filename = ft_strdup(cmd[0]);
	else
		filename = get_filename(cmd);
	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, sig_child);
		signal(SIGQUIT, SIG_DFL);
		execve(filename, cmd, g_mini.envs);
	}
	else
	{
		waitpid(pid, &i, 0);
		i = i >> 8;
		free(filename);
	}
	return (i);
}

static int	exec_builtin(char **cmd)
{
	if (!ft_strcmp("cd", cmd[0]))
		return (ft_cd(cmd));
	else if (!ft_strcmp("echo", cmd[0]))
		return (ft_echo(cmd));
	else if (!ft_strcmp("env", cmd[0]))
		return (ft_env());
	else if (!ft_strcmp("pwd", cmd[0]))
		return (ft_pwd());
	else if (!ft_strcmp("export", cmd[0]))
		return (ft_export(cmd));
	else if (!ft_strcmp("unset", cmd[0]))
		return (ft_unset(cmd));
	else if (!ft_strcmp("exit", cmd[0]))
		return (ft_exit(cmd));
	else
		return (0);
}

int	exec_command(char **cmd)
{
	if (cmd == NULL)
	{
		return (0);
	}
	if (is_builtin(cmd))
		return (exec_builtin(cmd));
	else if (is_binary(cmd))
		return (exec_bin(cmd));
	else
	{
		ft_error("minishell : ");
		ft_error(cmd[0]);
		ft_error(" : command not found\n");
		return (COMMAND_NOT_FOUND);
	}
}
