#include "../include/minishell.h"

int	fill_value(char *new, char *value)
{
	int		i;
	int		value_len;
	int		ret;

	value_len = ft_strlen(value);
	ret = value_len;
	i = 0;
	while (value_len > 0)
	{
		new[i] = value[i];
		i++;
		value_len--;
	}
	return (ret);
}

void	fill_changed_string(char *string, char *new, char *key, char *value)
{
	int		key_len;
	int		value_len;
	int		i;
	int		j;
	int		flag;

	key_len = ft_strlen(key) + 1;
	value_len = ft_strlen(value);
	i = 0;
	j = 0;
	flag = TRUE;
	while (string[i] != '\0')
	{
		if (string[i] == '$' && flag == TRUE)
		{
			i += key_len;
			j += fill_value(new + j, value);
			flag = FALSE;
		}
		else
			new[j++] = string[i++];
	}
	new[j] = '\0';
	return ;
}

char	*change_string(char *string, char *key, char *value)
{
	char	*new;
	int		key_len;
	int		value_len;
	int		string_len;

	key_len = ft_strlen(key) + 1;
	value_len = ft_strlen(value);
	string_len = ft_strlen(string);
	new = (char *)malloc
		(sizeof(char) * (string_len + (value_len - key_len) + 1));
	if (new == NULL)
		return (new);
	fill_changed_string(string, new, key, value);
	return (new);
}

void	manage_dollar(char **string)
{
	char	*key;
	char	*value;
	char	*new;
	char	**temp;

	key = find_key(*string);
	if (key == NULL)
		return ;
	if (!ft_strcmp(key, "?"))
		value = ft_itoa(g_mini.exit);
	else
		value = find_value(g_mini.envs, key);
	while (find_dollar(*string) >= 0)
	{
		new = change_string(*string, key, value);
		temp = string;
		free(*temp);
		*string = new;
	}
	return ;
}
