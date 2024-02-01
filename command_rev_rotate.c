/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rev_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:17:17 by rsimon            #+#    #+#             */
/*   Updated: 2024/01/22 21:50:12 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_rev_rotate(t_stack **a)
{
	t_stack	*last;
	t_stack	*cursor;

	if ((*a) == NULL || (*a)->next == NULL)
		return ;
	cursor = (*a);
	while (cursor->next->next != NULL)
	{
		cursor = cursor->next;
	}
	last = cursor->next;
	cursor->next = NULL;
	last->next = (*a);
	(*a) = last;
}

void	rra(t_stack **a)
{
	stack_rev_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	stack_rev_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	stack_rev_rotate(a);
	stack_rev_rotate(b);
	write(1, "rrr\n", 4);
}

void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while ((*b) != cheapest_node && (*a) != cheapest_node->target_node)
	{
		rrr(a, b);
	}
	assign_position(a);
	assign_position(b);
}
