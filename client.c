#include "minitalk.h"
#include <stdio.h>

static void	send_signal(pid_t pid, char c)
{
	unsigned char	bit;
	int				ret;

	bit = 0b10000000;
	while (bit)
	{
		if (c & bit)
			ret = kill(pid, SIGUSR1);
		else
			ret = kill(pid, SIGUSR2);
		if (ret < 0)
			ft_error("KILL ERROR!\n");
		bit = bit >> 1;
		usleep(42);
	}
}

static void	send_string(pid_t pid, char *str)
{
	while (*str)
	{
		send_signal(pid, *str);
		str++;
	}
	send_signal(pid, '\0');
}

static void	check_arg(int argc, char **argv)
{
	int		i;

	i = 0;
	if (argc != 3)
		ft_error("USAGE : ./client [pid] [message]\n");
	while (argv[1][i])
	{
		if (!ft_isdigit(argv[1][i]))
			ft_error("PID FORMAT ERROR!\n");
		i++;
	}
}

int	main(int argc, char **argv)
{
	check_arg(argc, argv);
	send_string(ft_atoi(argv[1]), argv[2]);
}
