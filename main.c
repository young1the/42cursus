#include "include/minishell.h"

t_mini	g_mini;

static void	copy_envp(char **envp)
{
	int		index;

	index = 0;
	while (envp[index] != NULL)
		index++;
	g_mini.envs = (char **)malloc(sizeof(char *) * (index + 1));
	index = 0;
	while (envp[index] != NULL)
	{
		g_mini.envs[index] = ft_strdup(envp[index]);
		index++;
	}
	g_mini.envs[index] = NULL;
}

static void	set_minishell(void)
{
	g_mini.signal = 0;
	rl_catch_signals = 0;
	rl_event_hook = event;
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, SIG_IGN);
	g_mini.stdin_fd = dup(STDIN_FILENO);
	g_mini.stdout_fd = dup(STDOUT_FILENO);
}

static int	is_cleanbuf(char *buf)
{
	int		i;

	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '<' || buf[i] == '>' || buf[i] == '|'
			|| buf[i] == '\0')
			return (0);
		i++;
	}
	return (1);
}

void	exec_minishell(char *buf)
{
	pid_t	pid;
	int		exit_num;

	add_history(buf);
	if (is_cleanbuf(buf))
		minishell_main(buf, STDIN_FILENO);
	else
	{
		pid = fork();
		if (pid == 0)
			minishell(buf, STDIN_FILENO);
		else
		{
			waitpid(pid, &(exit_num), 0);
			g_mini.exit = exit_num >> 8;
		}
	}
}

int	main(int argc, char **argv, char **envp)
{
	char	*buf;

	if (argc > 2 || argv == NULL)
		return (0);
	copy_envp(envp);
	while (42)
	{
		set_minishell();
		buf = readline("minishell : ");
		if (buf == NULL)
			return (0);
		if (g_mini.signal == 1)
		{
			g_mini.signal = 0;
			free(buf);
			continue ;
		}
		if (*buf != '\0')
			exec_minishell(buf);
		free(buf);
		buf = NULL;
	}
	return (0);
}
