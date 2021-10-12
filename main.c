#include "philosopher.h"

static void	check_args(int argc, char** argv)
{
	int		i;
	int		j;

	if (argc < 5 || argc > 6)
		ft_error("TOO FEW OR TOO MANY ARGUMENTS!\n");
	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				ft_error("ARGUMENTS MUST BE DIGIT!\n");
			j++;
		}
		i++;
	}
}

static void	fill_info(char** argv, t_info* info)
{
	int		i;

	info->number_of_philosophers = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		info->number_of_times_each_philosopher_must_eat
		= ft_atoi(argv[5]);
	else
		info->number_of_times_each_philosopher_must_eat
		= -1;
}

int	main(int argc, char** argv)
{
	t_info			info;
	pthread_mutex_t	mutex_lock;
	pthread_t		tid;

	check_args(argc, argv);
	fill_info(argv, &info);
	pthread_mutex_init(&mutex_lock, NULL);
	pthread_create(&tid, NULL, philosopher, (void*)&i);
	printf("done\n");
}
