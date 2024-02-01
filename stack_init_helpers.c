/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 09:44:45 by rsimon            #+#    #+#             */
/*   Updated: 2024/01/25 21:34:07 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_position(t_stack **a)
{
	int		i;
	int		centre;
	t_stack	*cursor;

	if ((*a) == NULL || a == NULL)
		return ;
	cursor = (*a);
	centre = stack_len(a) / 2;
	i = 0;
	while (cursor)
	{
		(cursor)->current_position = i;
		if (i <= centre)
			(cursor)->above_mid = true;
		else
			(cursor)->above_mid = false;
		(cursor) = (cursor)->next;
		i++;
	}
}

t_stack	*find_closest_node(t_stack *a, t_stack *b_cursor)
{
	long int	difference;
	t_stack		*current_a;
	t_stack		*target_node;

	difference = 2147483650;
	current_a = a;
	target_node = NULL;
	while (current_a)
	{
		if (current_a->number > b_cursor->number
			&& difference > current_a->number)
		{
			difference = current_a->number;
			target_node = current_a;
		}
		current_a = current_a->next;
	}
	return (target_node);
}

t_stack	*set_target_node(t_stack **a, t_stack **b)
{
	t_stack	*b_cursor;
	t_stack	*target_node;

	b_cursor = *b;
	if (*a == NULL || *b == NULL || a == NULL || b == NULL)
		return (NULL);
	while (b_cursor)
	{
		target_node = find_closest_node(*a, b_cursor);
		if (target_node == NULL)
			b_cursor->target_node = smallest_num(a);
		else
			b_cursor->target_node = target_node;
		b_cursor = b_cursor->next;
	}
	return ((*b)->target_node);
}

void	set_price(t_stack **a, t_stack **b)
{
	t_stack	*cursor_b;
	t_stack	*cursor_a;
	int		len_a;
	int		len_b;

	if (a == NULL || b == NULL || *a == NULL || *b == NULL)
		return ;
	cursor_b = (*b);
	cursor_a = (*a);
	len_a = stack_len(&cursor_a);
	len_b = stack_len(&cursor_b);
	while (cursor_b != NULL)
	{
		cursor_b->push_price = cursor_b->current_position;
		if (!(cursor_b)-> above_mid)
			cursor_b->push_price = len_b
				- cursor_b->current_position;
		if (cursor_b->target_node->above_mid)
			cursor_b->push_price += cursor_b->target_node->current_position;
		else
			cursor_b->push_price += len_a
				- (cursor_b)->target_node->current_position;
		cursor_b = cursor_b->next;
	}
}

void	set_cheapest(t_stack **b)
{
	t_stack	*cursor_b;
	long	best_match_value;
	t_stack	*best_node;

	(*b)->cheapest = 0;
	cursor_b = (*b);
	best_match_value = 2147483647;
	while (cursor_b)
	{
		if (cursor_b->push_price < best_match_value)
		{
			best_match_value = cursor_b->push_price;
			best_node = cursor_b;
		}
		cursor_b = cursor_b->next;
	}
	best_node->cheapest = true;
}
