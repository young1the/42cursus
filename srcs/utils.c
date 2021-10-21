#include "../inc/philosopher.h"

unsigned long long	get_time(void)
{
	struct timeval	time;
	unsigned long long	result;

	result = 0;
	gettimeofday(&time, NULL);
	result = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (result);
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
		printf ("%llu ms ", get_time() - philosopher->start_time);
		printf ("%d ", philosopher->id);
		printf ("%s\n", s);
		pthread_mutex_unlock(philosopher->microphone_p);
	}
}

void	spend_time(t_philosopher *philosopher)
{
	unsigned long long	start;
	unsigned long long	time;
	char				*s;

	start = get_time();
	if (philosopher->state == EATING)
		time = philosopher->menu->time_to_eat;
	if (philosopher->state == SLEEPING)
		time = philosopher->menu->time_to_sleep;
	while(get_time() < start + time)
		usleep(SLEEPTIME);
}

