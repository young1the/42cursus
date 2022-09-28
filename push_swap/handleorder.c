/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handleorder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: young-ch <young-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 18:37:01 by young-ch          #+#    #+#             */
/*   Updated: 2021/07/08 16:23:39 by young-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	free_order(t_order *order)
{
	t_order		*temp;
	t_order		*del;

	temp = order;
	while (temp != NULL)
	{
		del = temp;
		temp = temp->next;
		free(del->order);
		free(del);
	}
	return ;
}

int	check_order_list(char *order)
{
	int		len;

	len = ft_strlen(order);
	if (len == 0)
		return (1);
	if (order[0] == 's' && len == 2)
	{
		if (order[1] == 'a' || order[1] == 'b' || order[1] == 's')
			return (1);
	}
	if (order[0] == 'p' && len == 2)
	{
		if (order[1] == 'a' || order[1] == 'b')
			return (1);
	}
	if (order[0] == 'r' && len == 2)
	{
		if (order[1] == 'a' || order[1] == 'b' || order[1] == 'r')
			return (1);
	}
	if (order[0] == 'r' && order[1] == 'r' && len == 3)
	{
		if (order[2] == 'a' || order[2] == 'b' || order[2] == 'r')
			return (1);
	}
	return (0);
}

int	make_order_list(t_order *order)
{
	int			gnl;
	int			err;
	t_order		*temp;
	t_order		*new;

	temp = order;
	err = 0;
	while (get_next_line(0, &(temp->order)) > 0)
	{
		if (ft_strlen(temp->order) == 0)
			err++;
		if (err >= 2)
			return (0);
		if (!check_order_list(temp->order))
			return (0);
		new = init_order();
		temp->next = new;
		temp = temp->next;
	}
	return (1);
}

t_order	*init_order(void)
{
	t_order		*order;

	order = (t_order *)malloc(sizeof(t_order));
	if (order == NULL)
		return (NULL);
	order->next = NULL;
	return (order);
}
