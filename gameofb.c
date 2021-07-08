/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameofb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: young-ch <young-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 07:48:15 by young-ch          #+#    #+#             */
/*   Updated: 2021/07/07 14:44:08 by young-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	pa(t_stack *a, t_stack *b)
{
	int		temp_data;

	if (b->data == 0)
		return (0);
	temp_data = b->prev->data;
	pop_top(b);
	push_top(a, temp_data);
	write(1, "pa\n", 3);
	return (1);
}

int	sb(t_stack *b)
{
	int		temp;

	if (b->data < 2)
		return (0);
	temp = b->prev->data;
	b->prev->data = b->prev->prev->data;
	b->prev->prev->data = temp;
	write(1, "sb\n", 3);
	return (1);
}

int	rb(t_stack *b)
{
	int		temp_data;

	if (b->data == 0 && b->data == 1)
		return (0);
	temp_data = b->prev->data;
	pop_top(b);
	push_bottom(b, temp_data);
	write(1, "rb\n", 3);
	return (1);
}

int	rrb(t_stack *b)
{
	int		temp_data;

	if (b->data == 0 && b->data == 1)
		return (0);
	temp_data = b->next->data;
	pop_bottom(b);
	push_top(b, temp_data);
	write(1, "rrb\n", 4);
	return (1);
}
