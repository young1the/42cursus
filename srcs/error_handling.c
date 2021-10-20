#include "../inc/philosopher.h"

int	error_mutex_init(t_philosopher *philosopher, int id)
{
	int		i;

	i = 0;
	while (i++ < id)
		pthread_mutex_destroy(&(philosopher[i].fork));
	printf("ERROR! FAILED MUTEX INIT!\n");
	return (1);
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
