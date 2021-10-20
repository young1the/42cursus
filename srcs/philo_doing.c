#include "../inc/philosopher.h"

void	take_fork(t_philosopher *philosopher)
{
	t_philosopher	*next_philo;
	int				id;
	int				pop;

	id = philosopher->id;
	pop = philosopher->menu->number_of_philosophers;
	next_philo = &(philosopher->list[id % pop]);
	if (id % 2 == 0)
	{
		pthread_mutex_lock(&(philosopher->fork));
		pthread_mutex_lock(&(next_philo->fork));
	}
	else
	{
		pthread_mutex_lock(&(next_philo->fork));
		pthread_mutex_lock(&(philosopher->fork));
	}
	philosopher->state = TAKEN;
	print_state(philosopher);
}

void	release_fork(t_philosopher *philosopher)
{
	t_philosopher	*next_philo;
	int				id;
	int				pop;

	id = philosopher->id;
	pop = philosopher->menu->number_of_philosophers;
	next_philo = &(philosopher->list[id % pop]);
	if (id % 2 == 0)
	{
		pthread_mutex_unlock(&(philosopher->fork));
		pthread_mutex_unlock(&(next_philo->fork));
	}
	else
	{
		pthread_mutex_unlock(&(next_philo->fork));
		pthread_mutex_unlock(&(philosopher->fork));
	}
}

void	eating(t_philosopher *philosopher)
{
	take_fork(philosopher);
	philosopher->state = EATING;
	print_state(philosopher);
	looking_watch(philosopher);
	philosopher->empty_plate++;
	philosopher->life = get_time();
	release_fork(philosopher);
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
