/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pushswap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: young-ch <young-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 23:02:34 by young-ch          #+#    #+#             */
/*   Updated: 2021/07/07 15:08:42 by young-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push_swap(t_stack *a, t_stack *b)
{
	if (check_sorted(a))
		return ;
	if (a->data == 3)
		sort_three_numbers(a);
	if (a->data == 4)
		sort_four_numbers(a, b);
	if (a->data == 5)
		sort_five_numbers(a, b);
	a_to_b(a, b, a->data);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;

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
	push_swap(a, b);
	free_list(a);
	free_list(b);
	return (0);
}
