#include "philosopher.h"

static int	check_args(int argc, char** argv)
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

static void	fill_menu(char** argv, t_menu* menu)
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

int	error_mutex_init(t_philosopher *philosopher, int id)
{
	int		i;

	i = 0;
	while (i++ < id)
		pthread_mutex_destroy(&(philosopher[i].fork));
	printf("ERROR! FAILED MUTEX INIT!\n");
	return (1);
}

unsigned long long	get_time()
{
	struct timeval	time;
	unsigned long long	result;

	result = 0;
	gettimeofday(&time, NULL);
	result = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (result);
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
		// if (pthread_mutex_init(&(philosopher[i].philo_mutex), NULL))
		// 	return (error_mutex_init(philosopher, i));
		if (pthread_mutex_init(&(philosopher[i].fork), NULL))
			return (error_mutex_init(philosopher, i));
		i++;
	}
	return (0);
}

void farewell_philos(t_philosopher *philosopher, pthread_mutex_t *microphone)
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

int	set_table(char *alram, pthread_mutex_t *microphone)
{
	*alram = OFF;
	if (pthread_mutex_init(microphone, NULL))
	{
		printf("ERROR! FAILED MUTEX INIT!\n");
		return (1);
	}
	return (0);
}

void	print_state(t_philosopher *philosopher)
{
	char	*s;

	if (philosopher->state == EATING)
		s = "is eating";
	if (philosopher->state == SLEEPING)
		s = "is sleeping";
	if (philosopher->state == THINKING)
		s = "is thinking";
	if (philosopher->state == TAKEN)
		s = "has taken a fork";
	if (*(philosopher->alram_p) == OFF)
	{
		pthread_mutex_lock(philosopher->microphone_p);
		printf ("%llu ms ", get_time() - philosopher->clock);
		printf ("%d ", philosopher->id);
		printf ("%s\n", s);
		pthread_mutex_unlock(philosopher->microphone_p);
	}
}

void	looking_watch(t_philosopher *philosopher)
{
	unsigned long long	start;
	unsigned long long	target;
	char				*s;

	start = get_time();
	if (philosopher->state == EATING)
		target = philosopher->menu->time_to_eat;
	if (philosopher->state == SLEEPING)
		target = philosopher->menu->time_to_sleep;
	while(get_time() < target + start)
		usleep(1000);
}

void	eating(t_philosopher *philosopher)
{
	t_philosopher	*next_philo;
	int				id;
	int				pop;

	id = philosopher->id;
	pop = philosopher->menu->number_of_philosophers;
	next_philo = &(philosopher->list[id % pop]);
	pthread_mutex_lock(&(philosopher->fork));
	pthread_mutex_lock(&(next_philo->fork));
	philosopher->state = TAKEN;
	print_state(philosopher);
	philosopher->state = EATING;
	print_state(philosopher);
	looking_watch(philosopher);
	philosopher->empty_plate++;
	philosopher->life = get_time();
	pthread_mutex_unlock(&(philosopher->fork));
	pthread_mutex_unlock(&(next_philo->fork));
	// pthread_mutex_lock(&(philosopher->philo_mutex));
	// pthread_mutex_unlock(&(philosopher->philo_mutex));
}

void	odd_eating(t_philosopher *philosopher)
{
	t_philosopher	*next_philo;
	int				id;
	int				pop;

	id = philosopher->id;
	pop = philosopher->menu->number_of_philosophers;
	next_philo = &(philosopher->list[id % pop]);
	pthread_mutex_lock(&(next_philo->fork));
	pthread_mutex_lock(&(philosopher->fork));
	philosopher->state = TAKEN;
	print_state(philosopher);
	philosopher->state = EATING;
	print_state(philosopher);
	philosopher->empty_plate++;
	looking_watch(philosopher);
	philosopher->life = get_time();
	pthread_mutex_unlock(&(next_philo->fork));
	pthread_mutex_unlock(&(philosopher->fork));

	// pthread_mutex_lock(&(philosopher->philo_mutex));
	// pthread_mutex_unlock(&(philosopher->philo_mutex));
}

void	sleeping(t_philosopher *philosopher)
{
	philosopher->state = SLEEPING;
	print_state(philosopher);
	looking_watch(philosopher);
}

void	thinking(t_philosopher *philosopher)
{
	philosopher->state = THINKING;
	print_state(philosopher);
}

void	*philo_routine(void *param)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher*)param;
	while (*(philosopher->alram_p) == OFF)
	{
		if (philosopher->id % 2 == 0)
			eating(philosopher);
		else
			odd_eating(philosopher);
		sleeping(philosopher);
		thinking(philosopher);
	}
	// printf ("i am %d, and person who be by my right side is %d!\n", philosopher->id, next_philo->id);
	return (NULL);
}

void	*doctor_stop(t_philosopher* philosopher)
{
	char	*s;

	*(philosopher->alram_p) = ON;
	s = "died";
	pthread_mutex_lock(philosopher->microphone_p);
	printf ("%llu ms ", get_time() - philosopher->clock);
	printf ("%d ", philosopher->id);
	printf ("%s\n", s);
	pthread_mutex_unlock(philosopher->microphone_p);
	return (NULL);
}

void	*chef_stop(t_philosopher* philosopher)
{
	char	*s;

	pthread_mutex_lock(philosopher->microphone_p);
	*(philosopher->alram_p) = ON;
	s = "chef : you guys have ate enought.. now please leave here";
	printf ("%s\n", s);
	pthread_mutex_unlock(philosopher->microphone_p);
	return (NULL);
}

int		philo_is_full(t_philosopher *philosopher)
{
	static int	i;

	if (philosopher->menu->number_of_times_each_philosopher_must_eat < 0)
		return (0);
	if (philosopher[i].empty_plate >= philosopher->menu->number_of_times_each_philosopher_must_eat)
		i++;
	if (i == philosopher->menu->number_of_philosophers)
		return (1);
	else
		return (0);		
}

void	*moniter_routine(void *param)
{
	t_philosopher	*philosopher;
	int				i;
	int				pop;

	philosopher = (t_philosopher*)param;
	i = 0;
	pop = philosopher->menu->number_of_philosophers;
	while (42)
	{
		if (philo_is_full(philosopher))
			return (chef_stop(philosopher));
		if (i % pop == 0)
			i = 0;
		if (get_time() < philosopher[i % pop].life + philosopher->menu->time_to_die)
			i++;
		else
			return (doctor_stop(philosopher + i));
		usleep(100);
	}
	return (NULL);
}

int	error_thread_create(t_philosopher *philosopher, int id)
{
	int		i;

	i = 0;
	while (i++ < id)
		pthread_detach(philosopher[i].tid);
	printf("ERROR! FAILED THREAD CREATE!\n");
	return (1);
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
		philosopher[i].clock = get_time();
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

	// for (int i = 0; i < philosopher->menu->number_of_philosophers; i++)
	// 	pthread_join(philosopher[i].tid, NULL);
	return (0);
}

int	main(int argc, char** argv)
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
