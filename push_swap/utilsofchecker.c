/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsofchecker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: young-ch <young-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 18:18:08 by young-ch          #+#    #+#             */
/*   Updated: 2021/07/08 16:21:53 by young-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	swap_game(t_stack *a, t_stack *b, char *order)
{
	if (ft_strlen(order) != 2)
		return (0);
	if (order[1] == 'a')
		sa(a);
	else if (order[1] == 'b')
		sb(b);
	else if (order[1] == 's')
	{
		sa(a);
		sb(b);
	}
	else
		return (0);
	return (1);
}

int	push_game(t_stack *a, t_stack *b, char *order)
{
	if (ft_strlen(order) != 2)
		return (0);
	if (order[1] == 'a')
		pa(a, b);
	else if (order[1] == 'b')
		pb(a, b);
	else
		return (0);
	return (1);
}

int	rotate_game(t_stack *a, t_stack *b, char *order)
{
	if (ft_strlen(order) == 3)
		return (reverse_rotate(a, b, order));
	if (ft_strlen(order) != 2)
		return (0);
	if (order[1] == 'a')
		ra(a);
	else if (order[1] == 'b')
		rb(b);
	else if (order[1] == 'r')
	{
		ra(a);
		rb(b);
	}
	else
		return (0);
	return (1);
}

int	reverse_rotate(t_stack *a, t_stack *b, char *order)
{
	if (order[2] == 'a')
		rra(a);
	else if (order[2] == 'b')
		rrb(b);
	else if (order[2] == 'r')
	{
		rra(a);
		rrb(b);
	}
	else
		return (0);
	return (1);
}

int	play_order(t_stack *a, t_stack *b, t_order *order)
{
	t_order		*temp;
	int			ret;

	temp = order;
	ret = 1;
	while (temp != NULL)
	{
		if (temp->order[0] == 's')
			ret = swap_game(a, b, temp->order);
		else if (temp->order[0] == 'p')
			ret = push_game(a, b, temp->order);
		else if (temp->order[0] == 'r')
			ret = rotate_game(a, b, temp->order);
		temp = temp->next;
	}
	return (ret);
}
