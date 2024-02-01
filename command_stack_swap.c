/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_stack_swap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 00:33:47 by rsimon            #+#    #+#             */
/*   Updated: 2024/01/22 21:39:30 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_swap(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;

	if ((*a) != NULL && (*a)->next != NULL)
	{
		first = (*a);
		second = (*a)->next;
		first->next = second->next;
		second->next = first;
		(*a) = second;
	}
}

void	sa(t_stack **a)
{
	stack_swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	stack_swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack	**b)
{
	stack_swap(a);
	stack_swap(b);
	write(1, "ss\n", 3);
}
