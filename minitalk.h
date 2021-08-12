#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <sys/types.h>
# include <signal.h>
# include <stdlib.h>

void	ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_error(char *s);
int		ft_isdigit(int c);
int		ft_atoi(char *str);
char	*ft_itoa(int n);

#endif
