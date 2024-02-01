/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimon <rsimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 21:05:23 by rsimon            #+#    #+#             */
/*   Updated: 2024/01/26 16:57:05 by rsimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				number;
	int				current_position;
	int				push_price;
	struct s_stack	*next;
	struct s_stack	*target_node;
	bool			above_mid;
	bool			cheapest;
}	t_stack;

// a functions for stack moves
void			stack_rev_rotate(t_stack **a);
void			rra(t_stack **a);
void			rrb(t_stack **b);
void			rrr(t_stack **a, t_stack **b);
void			stack_init(int number, t_stack **a);
void			stack_push(t_stack **a, t_stack **b);
void			pa(t_stack **a, t_stack **b);
void			pb(t_stack **b, t_stack **a);
void			stack_rotate(t_stack **a);
void			ra(t_stack **a);
void			rb(t_stack **b);
void			rr(t_stack **a, t_stack **b);
void			stack_swap(t_stack **a);
void			sa(t_stack **a);
void			sb(t_stack **b);
void			ss(t_stack **a, t_stack	**b);

//helper functions
char			*ft_strchr(const char *s, int c);
long long int	ft_atoi(const char *str);
char			**ft_split(char const *s, char c);
char			*ft_strchr(const char *s, int c);
size_t			ft_strlen(const char *alpha);
void			ft_putstr_fd(char *s, int fd);

// stack utils 
int				stack_len(t_stack **a);
void			assign_position(t_stack **a);
t_stack			*set_target_node(t_stack **a, t_stack **b);
void			set_price(t_stack **a, t_stack **b);
void			set_cheapest(t_stack **b);
t_stack			*return_cheapest(t_stack *b);
void			move_nodes(t_stack **a, t_stack **b);
int				stack_sorted(t_stack **a);
void			push_swap(t_stack **a, t_stack **b);
t_stack			*last_node(t_stack **a);

//utils 1
t_stack			*highest_num(t_stack **a);
t_stack			*set_target_node(t_stack **a, t_stack **b);
t_stack			*smallest_num(t_stack **a);
void			init_node(t_stack **a, t_stack **b);
long int		*array_sorter(t_stack **a);

//algorithms
void			tiny_sort(t_stack **a);
void			loop(int argc, char **argv);

//error handler
void			error_syntax(char *argv, char **buffer, t_stack **a);
void			reptition(int number, t_stack **a, char **argv);
void			free_stack(t_stack **a);
void			error_free(t_stack **a, char **argv, bool flag_2);
void			free_buffer(char **argv);
void			rev_rotate_both(t_stack **a, t_stack **b,
					t_stack *cheapest_node);
void			out(void);
#endif
