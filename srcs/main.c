#include "../inc/philosopher.h"

static int	check_args(int argc, char **argv)
{
	int		i;
	int		j;

	if (argc < 5 || argc > 6)
	{
		printf("ERROR! TOO FEW OR TOO MANY ARGUMENTS!\n");
		return (1);
	}
	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				printf("ERROR! ARGUMENTS MUST BE DIGIT!\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static void	fill_menu(char **argv, t_menu *menu)
{
	menu->number_of_philosophers = ft_atoi(argv[1]);
	menu->time_to_die = ft_atoi(argv[2]);
	menu->time_to_eat = ft_atoi(argv[3]);
	menu->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		menu->number_of_times_each_philosopher_must_eat
			= ft_atoi(argv[5]);
	else
		menu->number_of_times_each_philosopher_must_eat
			= -1;
}

static int	set_table(char *alram, pthread_mutex_t *microphone)
{
	*alram = OFF;
	if (pthread_mutex_init(microphone, NULL))
	{
		printf("ERROR! FAILED MUTEX INIT!\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_menu			menu;
	char			alram;
	pthread_mutex_t	microphone;
	t_philosopher	*leader;

	if (check_args(argc, argv))
		return (1);
	fill_menu(argv, &menu);
	leader = invite_philos(&menu);
	if (leader == NULL)
		return (2);
	if (set_table(&alram, &microphone))
		return (3);
	if (set_philos(&menu, leader, &alram, &microphone))
		return (3);
	if (feed_philos(leader))
		return (4);
	farewell_philos(leader, &microphone);
	printf ("done\n");
	return (0);
}
