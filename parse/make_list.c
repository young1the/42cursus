#include "../include/minishell.h"

static void	cut_redirection(t_heads *heads,
			char *buf, int *index, int *prev_type)
{
	while (buf[*index] == '<' || buf[*index] == '>')
	{
		push_token(heads->token_head, buf[*index]);
		*index += 1;
	}
	push_list(heads->list_head, heads->token_head, prev_type, FALSE);
	*index -= 1;
}

static int	cut_quotes(t_heads *heads, char *buf,
				int *index, int *prev_type)
{
	char	quote;

	quote = buf[*index];
	*index += 1;
	while (buf[*index] != '\0')
	{
		if (buf[*index] == quote)
			break ;
		push_token(heads->token_head, buf[*index]);
		*index += 1;
	}
	if (buf[*index] == '\0')
	{
		clear_token(heads->token_head);
		clear_list(heads->list_head);
		ft_error("minishell : QUOTE UNCLOSED!\n");
		return (-1);
	}
	if (quote == '\"')
		push_list(heads->list_head, heads->token_head, prev_type, TRUE);
	else
		push_list(heads->list_head, heads->token_head, prev_type, FALSE);
	return (1);
}

static int	cut_by_delimiter(t_heads *heads, char *buf, int *index)
{
	static int	prev_type;
	int			checker;

	if (buf[*index] == '<' || buf[*index] == '>' || buf[*index] == '\"'
		|| buf[*index] == '\'' || buf[*index] == ' ' || buf[*index] == '\0')
	{
		push_list(heads->list_head, heads->token_head, &prev_type, TRUE);
		if (buf[*index] == '<' || buf[*index] == '>')
			cut_redirection(heads, buf, index, &prev_type);
		else if (buf[*index] == '\"' || buf[*index] == '\'')
		{
			checker = cut_quotes(heads, buf, index, &prev_type);
			return (checker);
		}
		return (1);
	}
	else
		return (0);
}

int	make_list(t_list *list_head, char *buf)
{
	int		index;
	int		checker;
	t_heads	heads;
	t_token	token_head;

	heads.list_head = list_head;
	heads.token_head = &(token_head);
	token_head.next = NULL;
	index = 0;
	while (buf[index] != '\0' && buf[index] != '|')
	{
		checker = cut_by_delimiter(&heads, buf, &index);
		if (checker == 0)
			push_token(&token_head, buf[index]);
		else if (checker < 0)
			return (1);
		index++;
	}
	cut_by_delimiter(&heads, buf, &index);
	return (0);
}
