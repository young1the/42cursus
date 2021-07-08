/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkbeforesort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: young-ch <young-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 07:54:21 by young-ch          #+#    #+#             */
/*   Updated: 2021/07/07 14:43:31 by young-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	check_sorted(t_stack *head)
{
	t_stack		*temp;

	temp = head->prev;
	while (temp->prev != head)
	{
		if (temp->data > temp->prev->data)
			return (0);
		temp = temp->prev;
	}
	return (1);
}

int	check_sorted_b(t_stack *head, int size)
{
	t_stack		*temp;

	temp = head->prev;
	while (size--)
	{
		if (temp->data < temp->prev->data)
			return (0);
		temp = temp->prev;
	}
	return (1);
}

int	check_duplication(t_stack *head)
{
	t_stack		*i_stack;
	t_stack		*j_stack;
	long long	temp_data;

	i_stack = head->next;
	while (i_stack != head)
	{
		temp_data = i_stack->data;
		j_stack = i_stack->next;
		while (j_stack != head)
		{
			if (temp_data == j_stack->data)
				return (1);
			j_stack = j_stack->next;
		}
		i_stack = i_stack->next;
	}
	return (0);
}

int	check_alphabet(char **argv)
{
	int		i;
	int		j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit_plus(argv[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
