/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:18:23 by rsimon            #+#    #+#             */
/*   Updated: 2024/01/26 15:36:18 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	*filler(t_stack **a, long int *argv, int len)
{
	int		i;
	t_stack	**cursor;

	cursor = a;
	i = 0;
	while (*cursor && i < len)
	{
		argv[i] = (*cursor)->number;
		(*cursor) = (*cursor)->next;
		i++;
	}
	return (argv);
}

void	sort_array(long int *array, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

long int	*array_sorter(t_stack **a)
{
	int				len;
	long int		*argv;

	len = stack_len(a);
	argv = malloc (sizeof(long int) * len);
	filler(a, argv, len);
	sort_array(argv, len);
	return (argv);
}
