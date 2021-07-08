/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: young-ch <young-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 03:53:39 by young-ch          #+#    #+#             */
/*   Updated: 2021/07/08 17:18:26 by young-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>

# define INTMAX 2147483647
# define INTMIN -2147483648

# define BUFFER_SIZE 1000
# define OPEN_MAX 100

typedef struct s_stack
{
	long long			data;
	struct s_stack		*prev;
	struct s_stack		*next;
}				t_stack;

typedef struct s_order
{
	char				*order;
	struct s_order		*next;
}				t_order;

typedef struct s_pivot
{
	int					large;
	int					small;
}				t_pivot;

typedef struct s_count
{
	int					pb;
	int					pa;
	int					ra;
	int					rb;
}				t_count;

long long		ft_atoll(const char *str);
int				ft_isdigit_plus(char c);
char			**ft_split(char const *s, char c);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
size_t			ft_strlen(const char *str);
int				ft_error(void);

int				get_next_line(int fd, char **line);

int				check_sorted(t_stack *head);
int				check_duplication(t_stack *head);
int				check_alphabet(char **argv);
int				check_sorted_b(t_stack *head, int size);

void			pop_top(t_stack *head);
void			pop_bottom(t_stack *head);
void			push_top(t_stack *head, int number);
void			push_bottom(t_stack *head, int number);

int				pb(t_stack *a, t_stack *b);
int				sa(t_stack *a);
int				ra(t_stack *a);
int				rra(t_stack *a);
void			rrr(t_stack *a, t_stack *b);

int				pa(t_stack *a, t_stack *b);
int				sb(t_stack *b);
int				rb(t_stack *b);
int				rrb(t_stack *b);

void			put_data_to_stack(t_stack *a, char **split);
void			put_random_number_to_stack(t_stack *a, char **argv);
void			free_list(t_stack *head);
t_stack			*init_stack(void);

void			push_swap(t_stack *a, t_stack *b);

void			swap_elements(int *a, int *b);
void			quick_sort(int *arr, int start, int end);
int				*list_to_arr(t_stack *head, int size);
void			find_pivot(t_stack *head, int range, t_pivot *pivot);
int				stop_ra(t_stack *a, int pivot);

void			sub_three_numbers(t_stack *a, int *arr);
void			sort_three_numbers(t_stack *a);
void			sort_four_numbers(t_stack *a, t_stack *b);
void			sort_five_numbers(t_stack *a, t_stack *b);

int				check_count_atob(t_stack *a, t_stack *b, int count);
int				check_count_btoa(t_stack *a, t_stack *b, int count);
void			rewind_stack(t_stack *a, t_stack *b, t_count count);
void			a_to_b(t_stack *a, t_stack *b, int size);
void			b_to_a(t_stack *a, t_stack *b, int size);

t_order			*init_order(void);
int				make_order_list(t_order *order);
int				free_n_ret(t_stack *a, t_stack *b, t_order *order, char c);
void			free_order(t_order *order);
int				check_order_list(char *order);

int				play_order(t_stack *a, t_stack *b, t_order *order);
int				reverse_rotate(t_stack *a, t_stack *b, char *order);
int				rotate_game(t_stack *a, t_stack *b, char *order);
int				push_game(t_stack *a, t_stack *b, char *order);
int				swap_game(t_stack *a, t_stack *b, char *order);

#endif
