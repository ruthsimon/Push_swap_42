/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_stack_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:37:56 by rsimon            #+#    #+#             */
/*   Updated: 2024/01/25 21:56:50 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(int number, t_stack **a)
{
	t_stack	*new_node;
	t_stack	*last;

	last = NULL;
	new_node = NULL;
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->number = number;
	new_node->cheapest = 0;
	if (*a == NULL)
	{
		*a = new_node;
	}
	else
	{
		last = last_node(a);
		last->next = new_node;
	}
}
