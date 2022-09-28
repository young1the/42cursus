#include "../include/minishell.h"

void	sig_handler(int sig)
{
	(void)sig;
	g_mini.signal = 1;
	rl_done = 1;
}

void	sig_child(int sig)
{
	(void)sig;
	g_mini.signal = 1;
	rl_done = 1;
	printf("\n");
}

int	event(void)
{
	return (42);
}
