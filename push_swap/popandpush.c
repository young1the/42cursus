/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   popandpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: young-ch <young-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 07:54:46 by young-ch          #+#    #+#             */
/*   Updated: 2021/07/03 15:53:27 by young-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	pop_top(t_stack *head)
{
	t_stack		*pop;

	pop = head->prev;
	if (pop == head)
		return ;
	head->prev = pop->prev;
	head->prev->next = head;
	head->data--;
	free(pop);
}

void	pop_bottom(t_stack *head)
{
	t_stack		*pop;

	pop = head->next;
	if (pop == head)
		return ;
	head->next = pop->next;
	head->next->prev = head;
	head->data--;
	free(pop);
}

void	push_top(t_stack *head, int number)
{
	t_stack		*temp;
	t_stack		*new_stack;

	new_stack = init_stack();
	if (new_stack == NULL)
		return ;
	new_stack->data = number;
	new_stack->next = head;
	if (head->prev == head)
	{
		head->next = new_stack;
		new_stack->prev = head;
	}
	else
	{
		head->prev->next = new_stack;
		new_stack->prev = head->prev;
	}
	head->prev = new_stack;
	head->data++;
	return ;
}

void	push_bottom(t_stack *head, int number)
{
	t_stack		*temp;
	t_stack		*new_stack;

	new_stack = init_stack();
	if (new_stack == NULL)
		return ;
	new_stack->data = number;
	new_stack->prev = head;
	if (head->next == head)
	{
		head->prev = new_stack;
		new_stack->next = head;
	}
	else
	{
		head->next->prev = new_stack;
		new_stack->next = head->next;
	}
	head->next = new_stack;
	head->data++;
	return ;
}
