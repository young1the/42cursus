#include "../include/minishell.h"

static int	check_signal(int status)
{
	if (status == 2)
	{
		printf("\n");
		return (130);
	}
	else if (status == 3)
	{
		printf("Quit : 3\n");
		return (131);
	}
	else
		return (0);
}

static char	*filename_abscheck(char **cmd)
{
	char	*filename;

	if (is_absolute_path(cmd))
		filename = ft_strdup(cmd[0]);
	else
		filename = get_filename(cmd);
	return (filename);
}

static int	exec_bin(char **cmd)
{
	char	*filename;
	pid_t	pid;
	int		status;

	status = 0;
	filename = filename_abscheck(cmd);
	signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, sig_child);
		signal(SIGQUIT, SIG_DFL);
		execve(filename, cmd, g_mini.envs);
	}
	else
	{
		waitpid(pid, &status, 0);
		signal(SIGINT, sig_handler);
		free(filename);
		if (WIFSIGNALED(status))
			return (check_signal(status));
	}
	return (status >> 8);
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
