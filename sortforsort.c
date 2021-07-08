/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortforsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: young-ch <young-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 08:55:45 by young-ch          #+#    #+#             */
/*   Updated: 2021/07/07 14:49:00 by young-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap_elements(int *a, int *b)
{
	int		temp;

	temp = *a;
	*a = *b;
	*b = temp;
	return ;
}

void	quick_sort(int *arr, int start, int end)
{
	int		pivot;
	int		i;
	int		j;

	if (start >= end)
		return ;
	pivot = start;
	i = pivot + 1;
	j = end;
	while (i <= j)
	{
		while (i <= end && arr[i] <= arr[pivot])
			i++;
		while (j > start && arr[j] >= arr[pivot])
			j--;
		if (i > j)
			swap_elements(&arr[pivot], &arr[j]);
		else
			swap_elements(&arr[i], &arr[j]);
	}
	quick_sort(arr, start, j - 1);
	quick_sort(arr, j + 1, end);
}

int	*list_to_arr(t_stack *head, int size)
{
	int		*arr;
	int		i;
	t_stack	*temp;

	if (size == 0)
		return (NULL);
	temp = head->prev;
	arr = (int *)malloc(sizeof(int) * size);
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		arr[i] = temp->data;
		temp = temp->prev;
		i++;
	}
	return (arr);
}

void	find_pivot(t_stack *head, int range, t_pivot *pivot)
{
	int		*arr;
	int		i;

	arr = list_to_arr(head, range);
	if (arr == NULL)
		return ;
	quick_sort(arr, 0, range - 1);
	i = range / 3;
	if (range % 3 == 2)
		i++;
	pivot->large = arr[i * 2 - 1];
	pivot->small = arr[i - 1];
	free(arr);
	return ;
}
