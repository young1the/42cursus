/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: young-ch <young-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 22:53:53 by young-ch          #+#    #+#             */
/*   Updated: 2021/07/07 16:01:05 by young-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	free_n_ret(t_stack *a, t_stack *b, t_order *order, char c)
{
	free_list(a);
	free_list(b);
	free_order(order);
	if (c == 'X')
		write(2, "Error\n", 7);
	return (0);
}

int	checker(t_stack *a, t_stack *b, t_order *order)
{
	if (!play_order(a, b, order))
		return (0);
	if (check_sorted(a) && b->next == b)
		write(1, "OK\n", 4);
	else
		write(1, "KO\n", 4);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_order		*order;

	if (argc < 2)
		return (ft_error());
	if (check_alphabet(argv))
		return (ft_error());
	a = init_stack();
	put_random_number_to_stack(a, argv);
	if (check_duplication(a))
	{
		free_list(a);
		return (ft_error());
	}
	b = init_stack();
	order = init_order();
	if (!make_order_list(order))
		return (free_n_ret(a, b, order, 'X'));
	if (!checker(a, b, order))
		return (free_n_ret(a, b, order, 'X'));
	return (free_n_ret(a, b, order, 'O'));
}
