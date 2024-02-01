/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 20:15:50 by rsimon            #+#    #+#             */
/*   Updated: 2024/01/25 19:31:08 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*last_node(t_stack **a)
{
	t_stack	*cursor;

	cursor = (*a);
	while (cursor != NULL && cursor->next != NULL)
	{
		cursor = cursor->next;
	}
	return (cursor);
}

t_stack	*smallest_num(t_stack **a)
{
	t_stack	*smallest;
	t_stack	*cursor;

	smallest = (*a);
	cursor = (*a)->next;
	while (cursor && smallest)
	{
		if (cursor->number < smallest->number)
			smallest = cursor;
		cursor = cursor->next;
	}
	return (smallest);
}

t_stack	*highest_num(t_stack **a)
{
	t_stack	*highest;
	t_stack	*cursor;

	if (a == NULL || *a == NULL)
		return (NULL);
	highest = (*a);
	cursor = (*a)->next;
	while (cursor)
	{
		if (cursor->number > highest->number)
			highest = cursor;
		cursor = cursor->next;
	}
	return (highest);
}

void	append_end(t_stack **b, int nbr)
{
	t_stack	*node_end;
	t_stack	*cursor;

	node_end = malloc(sizeof(t_stack));
	node_end->next = NULL;
	node_end->number = nbr;
	cursor = (*b);
	while (cursor != NULL && cursor->next != NULL)
	{
		cursor = cursor->next;
	}
	cursor->next = node_end;
	cursor = (*b);
}

int	stack_sorted(t_stack **a)
{
	t_stack	*cursor;

	cursor = (*a);
	if ((*a) == NULL)
		return (3);
	while (cursor->next != NULL)
	{
		if ((cursor->number) > (cursor->next->number))
		{
			return (0);
		}
		cursor = cursor->next;
	}
	return (1);
}
