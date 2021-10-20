#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdio.h>

#define OFF 0
#define ON 1

typedef enum			e_state
{
	DEAD,
	EATING,
	SLEEPING,
	THINKING,
	TAKEN
}						t_state;

typedef struct		s_menu
{
	int		number_of_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		number_of_times_each_philosopher_must_eat;
}					t_menu;

typedef struct				s_philosopher
{
	pthread_t				tid;
	int						id;
	t_state					state;
	t_menu					*menu;
	unsigned long long		watch;
	unsigned long long		clock;
	unsigned long long		life;
	int						empty_plate;
	char					*alram_p;
	pthread_mutex_t			*microphone_p;
	pthread_mutex_t			fork;
	struct s_philosopher	*list;
}							t_philosopher;

// utils
int		ft_atoi(char *str);
void	ft_error(char *s);
int		ft_isdigit(int c);
char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);

#endif
