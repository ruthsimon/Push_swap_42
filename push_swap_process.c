/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 09:30:16 by rsimon            #+#    #+#             */
/*   Updated: 2024/01/26 15:35:34 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_elements(t_stack **a, t_stack **b, long int *array, int len_median)
{
	int			i;
	int			j;
	t_stack		**cursor_a;

	i = len_median / 2;
	j = 0;
	cursor_a = a;
	while (*cursor_a)
	{
		if ((*cursor_a)->number >= array[i])
		{
			pb(b, a);
			j++;
		}
		else
		{
			ra(a);
			j++;
		}
		if (j == len_median)
			break ;
	}
}

void	push_to_b(t_stack **a, t_stack **b, long int *array, int len)
{
	int			i;
	t_stack		**cursor_a;

	i = len / 2;
	cursor_a = a;
	while (stack_len(cursor_a) > 3)
	{
		cursor_a = a;
		len = stack_len(cursor_a);
		i = len / 2;
		push_elements(cursor_a, b, array, len);
		i = i / 2;
	}
}

void	process_remaining_elements(t_stack **a, t_stack **b)
{
	tiny_sort(a);
	while (*b)
	{
		init_node(a, b);
		move_nodes(a, b);
	}
	assign_position(a);
	if (smallest_num(a)->above_mid)
		while (smallest_num(a) != (*a))
			ra(a);
	else
		while (smallest_num(a) != (*a))
			rra(a);
}

void	push_swap(t_stack **a, t_stack **b)
{
	int			len_median;
	t_stack		**cursor_a;
	long int	*array;
	t_stack		*tmp;

	tmp = *a;
	cursor_a = a;
	len_median = stack_len(a);
	array = array_sorter(&tmp);
	if (stack_len(cursor_a) <= 7)
		while (stack_len(cursor_a) > 3)
			pb (b, a);
	else
	{
		push_to_b(a, b, array, len_median);
	}
	process_remaining_elements(a, b);
	free(array);
}
