#include "minitalk.h"

static void	get_signal(int signumber)
{
	static unsigned char	c;
	static int				signal_received;

	signal_received++;
	if (signumber == SIGUSR1)
		c += 1 << (8 - signal_received);
	if (signal_received == 8)
	{
		if (c == '\0')
			ft_putchar_fd('\n', 1);
		else
			ft_putchar_fd(c, 1);
		c = 0;
		signal_received = 0;
	}
}

static void	print_pid(int pid)
{
	char	*str_pid;

	str_pid = ft_itoa(pid);
	ft_putstr_fd("PID : ", 1);
	ft_putstr_fd(str_pid, 1);
	ft_putchar_fd('\n', 1);
	free(str_pid);
}

int	main(void)
{
	int		pid;

	pid = getpid();
	print_pid(pid);
	signal(SIGUSR1, get_signal);
	signal(SIGUSR2, get_signal);
	while (42)
		pause();
}
