/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: young-ch <young-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 22:52:09 by young-ch          #+#    #+#             */
/*   Updated: 2021/07/03 15:58:51 by young-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sub_three_numbers(t_stack *a, int *arr)
{
	if (a->prev->data == arr[0])
	{
		if (a->next->data == arr[1])
		{
			rra(a);
			sa(a);
		}
	}
	if (a->prev->data == arr[1])
	{
		if (a->next->data == arr[0])
			rra(a);
		else
			sa(a);
	}
	if (a->prev->data == arr[2])
	{
		if (a->next->data == arr[0])
		{
			sa(a);
			rra(a);
		}
		else
			ra(a);
	}
}

void	sort_three_numbers(t_stack *a)
{
	int		*arr;

	arr = list_to_arr(a, 3);
	quick_sort(arr, 0, 2);
	sub_three_numbers(a, arr);
	free(arr);
	return ;
}

void	sort_four_numbers(t_stack *a, t_stack *b)
{
	while (a->data > 2)
	{
		if (a->prev->data > a->prev->prev->data)
			sa(a);
		pb(a, b);
	}
	if (a->prev->data > a->prev->prev->data)
		sa(a);
	if (b->prev->data < b->prev->prev->data)
		sb(b);
	while (b->data > 0)
	{
		pa(a, b);
		if (a->prev->data > a->prev->prev->data)
			sa(a);
	}
}

void	sort_five_numbers(t_stack *a, t_stack *b)
{
	int		*arr;

	arr = list_to_arr(a, 5);
	quick_sort(arr, 0, 4);
	while (a->data > 3)
	{
		if (a->prev->data > arr[0] && a->prev->data < arr[4])
			ra(a);
		else
			pb(a, b);
	}
	sort_three_numbers(a);
	pa(a, b);
	pa(a, b);
	if (a->prev->data > a->prev->prev->data)
		ra(a);
	else
	{
		sa(a);
		ra(a);
	}
	free(arr);
	return ;
}
