#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

#include <stdio.h>

enum			e_state
{
	DEAD,
	EATING,
	SLEEPING,
	THINKING
};

typedef struct		s_menu
{
	int		number_of_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		number_of_times_each_philosopher_must_eat;
}					t_menu;

typedef struct		s_philosopher
{
	int				philosopher_id;
	pthread_t		thread_id;
	unsigned int	last_eattime;
}					t_philosopher;

typedef struct		s_restaurant
{
	t_menu			*menu;
	t_philosopher	*philosopher;
	pthread_mutex_t	doctor;
	pthread_mutex_t	owner;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*microphone;
	int				empty_plate;
}					t_restaurant;
// utils
int		ft_atoi(char *str);
void	ft_error(char *s);
int		ft_isdigit(int c);
char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);

#endif
