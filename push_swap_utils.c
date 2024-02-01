/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:32:45 by rsimon            #+#    #+#             */
/*   Updated: 2024/01/25 21:33:54 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	t;

	t = (char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == t)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (t == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

static int	signof(char c, int *i)
{
	int	sign;

	sign = 1;
	if (c == '-' || c == '+')
	{
		if (c == '-')
		{
			sign = -1;
		}
		(*i)++;
	}
	return (sign);
}

long long int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	long long			res;
	int					digit;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	sign = signof(str[i], &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		digit = str[i] - '0';
		res = res * 10;
		if (res < -9223372036854775807 || res > 9223372036854775807
			|| res < -2147483648 || res > 2147483647)
			return (((long long int)INT_MAX) + 1);
		res += digit;
		i++;
	}
	return ((long long int)(res * sign));
}

t_stack	*return_cheapest(t_stack *b)
{
	if (b == NULL)
		return (NULL);
	while (b)
	{
		if (b->cheapest)
			return (b);
		b = b->next;
	}
	return (NULL);
}

int	stack_len(t_stack **a)
{
	int		count;
	t_stack	*cursor;

	count = 0;
	cursor = (*a);
	if (a == NULL)
		return (0);
	while (cursor)
	{
		++count;
		(cursor) = (cursor)->next;
	}
	return (count);
}
