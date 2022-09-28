/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlestack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: young-ch <young-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 07:52:52 by young-ch          #+#    #+#             */
/*   Updated: 2021/07/07 15:08:15 by young-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->data = 0;
	stack->next = stack;
	stack->prev = stack;
	return (stack);
}

void	put_data_to_stack(t_stack *a, char **split)
{
	int			i;
	int			j;
	long long	data;

	i = 0;
	if (split[i] == NULL)
	{
		write(1, "Error\n", 7);
		exit(0);
	}
	while (split[i] != NULL)
	{
		data = ft_atoll(split[i]);
		if (data > INTMAX || data < INTMIN)
		{
			free_list(a);
			write(1, "Error\n", 7);
			exit(0);
		}
		push_bottom(a, data);
		data = 0;
		free(split[i]);
		i++;
	}
	return ;
}

void	put_random_number_to_stack(t_stack *a, char **argv)
{
	int		i;
	char	**split;

	i = 1;
	while (argv[i] != NULL)
	{
		split = ft_split(argv[i], ' ');
		if (split == NULL)
			return ;
		put_data_to_stack(a, split);
		free(split);
		i++;
	}
	return ;
}

void	free_list(t_stack *head)
{
	t_stack		*temp;
	t_stack		*delete;

	temp = head->next;
	while (temp != head)
	{
		delete = temp;
		temp = temp->next;
		free(delete);
	}
	free(head);
}

void	rewind_stack(t_stack *a, t_stack *b, t_count count)
{
	if (a->data == count.ra)
		count.ra = 0;
	if (b->data == count.rb)
		count.rb = 0;
	if (count.ra == count.rb)
	{
		while (count.ra-- > 0)
			rrr(a, b);
	}
	else if (count.ra > count.rb)
	{
		count.ra -= count.rb;
		while (count.rb-- > 0)
			rrr(a, b);
		while (count.ra-- > 0)
			rra(a);
	}
	else if (count.rb > count.ra)
	{
		count.rb -= count.ra;
		while (count.ra-- > 0)
			rrr(a, b);
		while (count.rb-- > 0)
			rrb(b);
	}
}
