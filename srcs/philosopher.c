#include "../inc/philosopher.h"

t_philosopher	*invite_philos(t_menu *menu)
{
	int				population;
	t_philosopher	*leader;

	population = menu->number_of_philosophers;
	leader = (t_philosopher*)malloc(sizeof(t_philosopher) * population);
	if (leader == NULL)
	{
		printf("ERROR! CANT MALLOC!\n");
		return (NULL);
	}
	return (leader);
}

int	set_philos(t_menu *menu, t_philosopher *philosopher,
char *alram, pthread_mutex_t *microphone)
{
	int		i;
	int		population;
	int		must_eat;

	i = 0;
	population = menu->number_of_philosophers;
	must_eat = menu->number_of_times_each_philosopher_must_eat;
	while (i < population)
	{
		philosopher[i].id = i + 1;
		philosopher[i].state = THINKING;
		philosopher[i].menu = menu;
		philosopher[i].empty_plate = 0;
		philosopher[i].alram_p = alram;
		philosopher[i].microphone_p = microphone;
		philosopher[i].list = philosopher;
		if (pthread_mutex_init(&(philosopher[i].fork), NULL))
			return (error_mutex_init(philosopher, i));
		i++;
	}
	return (0);
}

int	feed_philos(t_philosopher* philosopher)
{
	int			i;
	int			result;
	pthread_t	moniter_tid;
	pthread_t	chef_tid;

	i = 0;
	while (i < philosopher->menu->number_of_philosophers)
	{
		philosopher[i].start = get_time();
		philosopher[i].life = get_time();
		result = pthread_create
		(&(philosopher[i].tid), NULL, philo_routine, (void*)&(philosopher[i]));
		if (result != 0)
			return(error_thread_create(philosopher, i));
		i++;
	}
	result = pthread_create
	(&(moniter_tid), NULL, moniter_routine, (void*)philosopher);
	if (result != 0)
		return(error_thread_create(philosopher, philosopher->menu->number_of_philosophers));
	pthread_join(moniter_tid, NULL);
	return (0);
}

void	farewell_philos(t_philosopher *philosopher, pthread_mutex_t *microphone)
{
	int		id;
	int		population;

	id = 0;
	population = philosopher->menu->number_of_philosophers;
	while (id++ < population)
		pthread_mutex_destroy(&(philosopher[id].fork));
	free(philosopher);
	pthread_mutex_destroy(microphone);
}

void	*philo_routine(void *param)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher*)param;
	while (*(philosopher->alram_p) == OFF)
	{
		eating(philosopher);
		sleeping(philosopher);
		thinking(philosopher);
	}
	return (NULL);
}
