/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 11:20:28 by rsimon            #+#    #+#             */
/*   Updated: 2024/01/26 18:50:05 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	out(void)
{
	ft_putstr_fd("Error\n", 2);
	exit (1);
}

void	check_int(long long int x, t_stack *a, char **buffer )
{
	if (x > INT_MAX || x < INT_MIN)
	{
		ft_putstr_fd("Error\n", 2);
		error_free(&a, buffer, true);
		out();
	}
}

t_stack	*initializer(int argc, char **argv, t_stack *a)
{
	int				i;
	long long int	x;
	int				j;
	char			**buffer;

	i = 0;
	x = 0;
	j = 1;
	while (j < argc)
	{
		i = 0;
		buffer = ft_split(argv[j], ' ');
		while (buffer[i] != NULL)
		{
			error_syntax(buffer[i], buffer, &a);
			x = ft_atoi(buffer[i]);
			reptition(x, &a, buffer);
			check_int(x, a, buffer);
			stack_init(x, &a);
			i++;
		}
		free_buffer(buffer);
		j++;
	}
	return (a);
}

void	not_sorted(t_stack *a, t_stack *b, int len, t_stack *tmp)
{
	long int	*array;

	array = NULL;
	(void)tmp;
	if (!stack_sorted(&a))
	{
		if (len == 2)
			sa(&a);
		else if (len == 3)
			tiny_sort(&a);
		else
		{
			array = array_sorter(&tmp);
			push_swap(&a, &b);
		}
	}
	free_stack(&a);
	free(array);
}

int	main(int argc, char **argv)
{
	t_stack			*a;
	t_stack			*b;
	t_stack			*tmp; 
	int				len;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
	{
		if (argc == 1)
			return (0);
		out();
	}
	loop(argc, argv);
	a = initializer(argc, argv, a);
	tmp = a;
	len = stack_len(&a);
	not_sorted(a, b, len, tmp);
	exit(0);
}
