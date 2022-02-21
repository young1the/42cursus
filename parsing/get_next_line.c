#include "parsing.h"

static int	get_index(char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static int	get_return(char **line, char **files, int bytes)
{
	int		i;
	char	*temp;

	if (bytes == 0 && *files == NULL)
	{
		*line = ft_strdup("");
		return (0);
	}
	i = get_index(*files);
	if (i < 0)
	{
		*line = ft_strdup(*files);
		free(*files);
		*files = NULL;
		return (0);
	}
	else
	{
		(*files)[i] = '\0';
		temp = *files;
		*line = ft_strdup(temp);
		*files = ft_strdup(temp + i + 1);
		free(temp);
		return (1);
	}
}

static void	get_merge(char **files, char *buffer)
{
	char	*temp;

	temp = ft_strdup(*files);
	free(*files);
	*files = ft_strjoin(temp, buffer);
	free(temp);
}

int			get_next_line(int fd, char **line)
{
	static char	*files;
	char		*buffer;
	int			bytes;

	if (fd < 0 || !line)
		return (-1);
	buffer = (char *)malloc(sizeof(char) * (42 + 1));
	while ((bytes = read(fd, buffer, 42)) > 0)
	{
		buffer[bytes] = '\0';
		if (!files)
			files = ft_strdup(buffer);
		else
			get_merge(&files, buffer);
		if (get_index(files) != -1)
			break ;
		free (buffer);
	}
	if (bytes < 0)
		return (-1);
	return (get_return(line, &files, bytes));
}
