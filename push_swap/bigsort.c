/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: young-ch <young-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 22:51:50 by young-ch          #+#    #+#             */
/*   Updated: 2021/07/07 15:03:14 by young-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	check_count_atob(t_stack *a, t_stack *b, int count)
{
	if (count == 2 || count == 3)
	{
		if ((a->prev->data) > (a->prev->prev->data))
			sa(a);
		if (count == 3)
		{
			if (a->prev->prev->data > a->prev->prev->prev->data)
			{
				ra(a);
				sa(a);
				rra(a);
				if (a->prev->data > a->prev->prev->data)
					sa(a);
			}
		}
	}
	if (count >= 0 && count <= 3)
		return (0);
	return (1);
}

int	check_count_btoa(t_stack *a, t_stack *b, int count)
{
	if (check_sorted_b(b, count))
	{
		while (count--)
			pa(a, b);
		return (0);
	}
	if (count == 2)
	{
		if ((b->prev->data) < (b->prev->prev->data))
			sb(b);
		pa(a, b);
		pa(a, b);
	}
	if (count == 1)
		pa(a, b);
	if (count >= 0 && count <= 2)
		return (0);
	return (1);
}

void	a_to_b(t_stack *a, t_stack *b, int size)
{
	t_count			count;
	t_pivot			pivot;

	if (check_sorted(a))
		return ;
	if (!check_count_atob(a, b, size))
		return ;
	find_pivot(a, size, &pivot);
	count = (t_count){0, 0, 0, 0};
	while (size-- > 0)
	{
		if (a->prev->data > pivot.large)
			count.ra += ra(a);
		else
		{
			count.pb += pb(a, b);
			if (b->prev->data > pivot.small)
				count.rb += rb(b);
		}
	}
	rewind_stack(a, b, count);
	a_to_b(a, b, count.ra);
	b_to_a(a, b, count.rb);
	b_to_a(a, b, count.pb - count.rb);
}

void	b_to_a(t_stack *a, t_stack *b, int size)
{
	t_count			count;
	t_pivot			pivot;

	if (!check_count_btoa(a, b, size))
		return ;
	find_pivot(b, size, &pivot);
	count = (t_count){0, 0, 0, 0};
	while (size-- > 0)
	{
		if (b->prev->data <= pivot.small)
			count.rb += rb(b);
		else
		{
			count.pa += pa(a, b);
			if (a->prev->data <= pivot.large)
				count.ra += ra(a);
		}
	}
	a_to_b(a, b, count.pa - count.ra);
	rewind_stack(a, b, count);
	a_to_b(a, b, count.rb);
	b_to_a(a, b, count.ra);
}
