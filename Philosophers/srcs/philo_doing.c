#include "../inc/philosopher.h"

void	taking_fork(t_philosopher *philosopher)
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
}

void	releasing_fork(t_philosopher *philosopher)
{
	t_philosopher	*next_philo;
	int				id;
	int				pop;

	id = philosopher->id;
	pop = philosopher->menu->number_of_philosophers;
	next_philo = &(philosopher->list[id % pop]);
	pthread_mutex_unlock(&(philosopher->fork));
	pthread_mutex_unlock(&(next_philo->fork));
}

void	eating(t_philosopher *philosopher)
{
	if (philosopher->id % 2 == 0)
		usleep(SLEEPTIME);
	taking_fork(philosopher);
	philosopher->state = EATING;
	print_state(philosopher);
	spend_time(philosopher);
	philosopher->empty_plate++;
	philosopher->life_time = get_time();
	releasing_fork(philosopher);
}

void	sleeping(t_philosopher *philosopher)
{
	philosopher->state = SLEEPING;
	print_state(philosopher);
	spend_time(philosopher);
}

void	thinking(t_philosopher *philosopher)
{
	philosopher->state = THINKING;
	print_state(philosopher);
}
