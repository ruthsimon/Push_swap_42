/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:25:29 by rsimon            #+#    #+#             */
/*   Updated: 2023/12/05 20:46:21 by rsimon           ###   ########.fr       */
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

// #include <stdio.h>
// #include <string.h>
// int main ()
// {
//     char x[] = "tripoulieee";
//     //printf("%s", ft_strchr(x, 't'+256));
// 	printf("%s", strchr(x, 't' + 2));

//     return (0);
// }
