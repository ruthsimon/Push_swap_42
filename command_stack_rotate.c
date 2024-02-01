/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_stack_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 00:23:38 by rsimon            #+#    #+#             */
/*   Updated: 2024/01/25 17:59:25 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_rotate(t_stack **a)
{
	t_stack	*first;
	t_stack	*cursor;

	if (a == NULL || (*a) == NULL)
		return ;
	first = (*a);
	(*a) = (*a)->next;
	cursor = (*a);
	while (cursor->next != NULL)
	{
		cursor = cursor->next;
	}
	cursor->next = first;
	cursor->next->next = NULL;
	cursor = (*a);
}

void	ra(t_stack **a)
{
	stack_rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	stack_rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	stack_rotate(a);
	stack_rotate(b);
	write(1, "rr\n", 3);
}
