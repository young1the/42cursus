#ifndef LIBFT_H
# define LIBFT_H

# include "../include/cub3d.h"

int		ft_atoi(const char *str);
void	*ft_memset(void *s, int c, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strndup(const char *s1, int n);

#endif
