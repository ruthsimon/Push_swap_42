/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_process2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:03:55 by rsimon            #+#    #+#             */
/*   Updated: 2024/01/26 16:57:30 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while ((*b) != cheapest_node && (*a) != cheapest_node->target_node)
	{
		rr(a, b);
	}
	assign_position(a);
	assign_position(b);
}

void	finish_rotation(t_stack **stack, t_stack *cheapest_node,
char name_stack)
{
	while (*stack != cheapest_node)
	{
		if (name_stack == 'a')
		{
			if (cheapest_node->above_mid)
				ra(stack);
			else
				rra(stack);
		}
		else if (name_stack == 'b')
		{
			if (cheapest_node->above_mid)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	move_nodes(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = return_cheapest(*b);
	if (cheapest_node->above_mid
		&& cheapest_node->target_node->above_mid)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_mid)
		&& !(cheapest_node->target_node->above_mid))
		rev_rotate_both(a, b, cheapest_node);
	finish_rotation(b, cheapest_node, 'b');
	finish_rotation(a, cheapest_node->target_node, 'a');
	pa(b, a);
}

void	loop(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] == ' ')
			j++;
		if (argv[i][j] == '\0')
		{
			ft_putstr_fd("Error\n", 2);
			exit (1);
		}
		else
			i++;
	}
}

void	init_node(t_stack **a, t_stack **b)
{
	assign_position(a);
	assign_position(b);
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}
