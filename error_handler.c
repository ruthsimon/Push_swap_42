/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 23:21:41 by rsimon            #+#    #+#             */
/*   Updated: 2024/01/26 16:45:35 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **a)
{
	t_stack	*tmp;

	while (*a)
	{
		tmp = *a;
		(*a) = (*a)->next;
		free(tmp);
	}
}

void	free_buffer(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
		free(argv[i++]);
	free(argv);
}

void	error_syntax(char *str_nbr, char **buffer, t_stack **a)
{
	if (!(*str_nbr == '+' || *str_nbr == '-'
			|| (*str_nbr >= '0' && *str_nbr <= '9')))
	{
		ft_putstr_fd("Error\n", 2);
		error_free(a, buffer, true);
		out();
	}
	if ((*str_nbr == '+'
			|| *str_nbr == '-')
		&& !(str_nbr[1] >= '0' && str_nbr[1] <= '9'))
	{
		ft_putstr_fd("Error\n", 2);
		error_free(a, buffer, true);
		exit (1);
	}
	while (*++str_nbr)
	{
		if (!(*str_nbr >= '0' && *str_nbr <= '9'))
		{
			ft_putstr_fd("Error\n", 2);
			error_free(a, buffer, true);
			exit (1);
		}
	}
	return ;
}

void	reptition(int number, t_stack **a, char **argv)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp)
	{
		if (number == (tmp)->number)
		{
			ft_putstr_fd("Error\n", 2);
			tmp = *a;
			error_free(&tmp, argv, true);
			exit (1);
		}
		tmp = tmp->next;
	}
	return ;
}

void	error_free(t_stack **a, char **argv, bool flag_2)
{
	free_stack(a);
	if (flag_2)
		free_buffer(argv);
	exit(1);
}
