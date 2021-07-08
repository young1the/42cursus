/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: young-ch <young-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 23:31:46 by young-ch          #+#    #+#             */
/*   Updated: 2021/07/07 14:52:45 by young-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

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

static int	get_return(int fd, char **line, char **files, int bytes)
{
	int		i;
	char	*temp;

	if (bytes == 0 && !files[fd])
	{
		*line = ft_strdup("");
		return (0);
	}
	i = get_index(files[fd]);
	if (i == -1)
	{
		*line = ft_strdup(files[fd]);
		free(files[fd]);
		files[fd] = NULL;
		return (0);
	}
	else
	{
		files[fd][i] = '\0';
		temp = files[fd];
		*line = ft_strdup(temp);
		files[fd] = ft_strdup(temp + i + 1);
		free(temp);
		return (1);
	}
}

static void	get_merge(int fd, char **files, char *buffer)
{
	char	*temp;

	temp = ft_strdup(files[fd]);
	free(files[fd]);
	files[fd] = ft_strjoin(temp, buffer);
	free(temp);
}

int	get_next_line(int fd, char **line)
{
	static char	*files[OPEN_MAX];
	char		*buffer;
	int			bytes;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	bytes = read(fd, buffer, BUFFER_SIZE);
	while (bytes > 0)
	{
		buffer[bytes] = '\0';
		if (!files[fd])
			files[fd] = ft_strdup(buffer);
		else
			get_merge(fd, files, buffer);
		if (get_index(files[fd]) != -1)
			break ;
		bytes = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	if (bytes < 0)
		return (-1);
	return (get_return(fd, line, files, bytes));
}
