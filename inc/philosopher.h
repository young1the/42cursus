#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdio.h>

#define OFF 0
#define ON 1

typedef enum				e_state
{
	DEAD,
	EATING,
	SLEEPING,
	THINKING,
	TAKEN
}							t_state;

typedef struct				s_menu
{
	int						number_of_philosophers;
	int						time_to_die;
	int						time_to_eat;
	int						time_to_sleep;
	int						number_of_times_each_philosopher_must_eat;
}							t_menu;

typedef struct				s_philosopher
{
	pthread_t				tid;
	int						id;
	t_state					state;
	t_menu					*menu;
	unsigned long long		start;
	unsigned long long		life;
	int						empty_plate;
	char					*alram_p;
	pthread_mutex_t			*microphone_p;
	pthread_mutex_t			fork;
	struct s_philosopher	*list;
}							t_philosopher;

// srcs
//// error_handling.c
int					error_mutex_init(t_philosopher *philosopher, int id);
int					error_thread_create(t_philosopher *philosopher, int id);
//// moniter.c
void				*doctor_stop(t_philosopher* philosopher);
void				*chef_stop(t_philosopher* philosopher);
int					philo_is_full(t_philosopher *philosopher);
void				*moniter_routine(void *param);
//// philo_doing.c
void				take_fork(t_philosopher *philosopher);
void				release_fork(t_philosopher *philosopher);
void				eating(t_philosopher *philosopher);
void				sleeping(t_philosopher *philosopher);
void				thinking(t_philosopher *philosopher);
//// philosopher.c
t_philosopher		*invite_philos(t_menu *menu);
int					set_philos(t_menu *menu, t_philosopher *philosopher,
char *alram, pthread_mutex_t *microphone);
int					feed_philos(t_philosopher* philosopher);
void				farewell_philos(t_philosopher *philosopher, pthread_mutex_t *microphone);
void				*philo_routine(void *param);
//// utils.c
unsigned long long	get_time(void);
void				print_state(t_philosopher *philosopher);
void				looking_watch(t_philosopher *philosopher);
// libft
int					ft_atoi(char *str);
void				ft_error(char *s);
int					ft_isdigit(int c);
char				*ft_itoa(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
size_t				ft_strlen(const char *str);

#endif
