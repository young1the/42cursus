#include "../inc/philosopher.h"

void	*doctor_stop(t_philosopher *philosopher)
{
	char	*s;

	*(philosopher->alram_p) = ON;
	s = "died";
	pthread_mutex_lock(philosopher->microphone_p);
	printf ("%llu ms ", get_time() - philosopher->start_time);
	printf ("%d ", philosopher->id);
	printf ("%s\n", s);
	pthread_mutex_unlock(philosopher->microphone_p);
	return (NULL);
}

void	*chef_stop(t_philosopher *philosopher)
{
	char	*s;

	pthread_mutex_lock(philosopher->microphone_p);
	*(philosopher->alram_p) = ON;
	s = "All philosophers are satisfied..!";
	printf ("%s\n", s);
	pthread_mutex_unlock(philosopher->microphone_p);
	return (NULL);
}

int	philo_is_full(t_philosopher *philosopher)
{
	static int	i;

	if (philosopher->menu->number_of_times_each_philosopher_must_eat < 0)
		return (0);
	if (philosopher[i].empty_plate
		>= philosopher->menu->number_of_times_each_philosopher_must_eat)
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

	philosopher = (t_philosopher *)param;
	i = 0;
	pop = philosopher->menu->number_of_philosophers;
	while (42)
	{
		if (philo_is_full(philosopher))
			return (chef_stop(philosopher));
		if (i % pop == 0)
			i = 0;
		if (get_time() < philosopher[i % pop].life_time
		+ philosopher->menu->time_to_die)
			i++;
		else
			return (doctor_stop(philosopher + i));
		usleep(SLEEPTIME);
	}
	return (NULL);
}
