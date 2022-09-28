/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameofa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: young-ch <young-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 07:47:58 by young-ch          #+#    #+#             */
/*   Updated: 2021/07/07 14:43:54 by young-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	pb(t_stack *a, t_stack *b)
{
	int		temp_data;

	if (a->data == 0)
		return (0);
	temp_data = a->prev->data;
	pop_top(a);
	push_top(b, temp_data);
	write(1, "pb\n", 3);
	return (1);
}

int	sa(t_stack *a)
{
	int		temp;

	if (a->data < 2)
		return (0);
	temp = a->prev->data;
	a->prev->data = a->prev->prev->data;
	a->prev->prev->data = temp;
	write(1, "sa\n", 3);
	return (1);
}

int	ra(t_stack *a)
{
	int		temp_data;

	if (a->data == 0 && a->data == 1)
		return (0);
	temp_data = a->prev->data;
	pop_top(a);
	push_bottom(a, temp_data);
	write(1, "ra\n", 3);
	return (1);
}

int	rra(t_stack *a)
{
	int		temp_data;

	if (a->data == 0 && a->data == 1)
		return (0);
	temp_data = a->next->data;
	pop_bottom(a);
	push_top(a, temp_data);
	write(1, "rra\n", 4);
	return (1);
}

void	rrr(t_stack *a, t_stack *b)
{
	int		temp_data;
	int		flag;

	flag = 0;
	if (a->data == 0 && a->data == 1)
		flag = 1;
	else
	{
		temp_data = a->next->data;
		pop_bottom(a);
		push_top(a, temp_data);
	}
	if (b->data == 0 && b->data == 1)
		flag = 2;
	else
	{
		temp_data = b->next->data;
		pop_bottom(b);
		push_top(b, temp_data);
	}
	if (flag == 0)
		write(1, "rrr\n", 4);
	return ;
}
