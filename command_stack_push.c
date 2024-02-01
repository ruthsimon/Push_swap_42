/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_stack_push.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:17:06 by rsimon            #+#    #+#             */
/*   Updated: 2024/01/22 21:38:30 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_push(t_stack **a, t_stack **b)
{
	t_stack	*first;

	first = (*a);
	(*a) = (*a)->next;
	first->next = NULL;
	first->next = (*b);
	(*b) = first;
}

void	pa(t_stack **a, t_stack **b)
{
	stack_push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	stack_push(b, a);
	write(1, "pb\n", 3);
}
