/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seralves <seralves@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 21:18:57 by seralves          #+#    #+#             */
/*   Updated: 2025/09/25 20:39:17 by seralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				num;
	int				index;
	int				sort_index;
	int				cost;
	int				is_above_middle;
	int				is_cheapest;
	struct s_stack	*next;
	struct s_stack	*target_node;
}					t_stack;

struct	s_iter
{
	int		i;
	int		j;
	int		value;
	int		is_first;
	char	*str1;
	char	*str2;
};

t_stack	*process_arguments(int argc, char **argv);
t_stack	*process_arguments_string(char *str);
int		has_repeated_args(char **split_str);
int		has_no_chars_except_spaces(char *str);
void	free_split_str(char **str);
void	free_stack(t_stack **stack);
void	terminate_stack(t_stack	**stack);
void	terminate_stack_split(t_stack **stack, char **str);
void	display_stack(t_stack *stack);
void	display_stack_complete(t_stack *stack);
int		ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);
int		has_overflow(char *str);
int		has_invalid_syntax(char *str);
int		is_valid_arg(char *str);
int		is_valid_split(char **split_str);
t_stack	*create_new_node(int new_data);
int		stack_size(t_stack *stack);
int		stack_is_sorted(t_stack *stack);
t_stack	*get_bottom_node(t_stack *stack);
char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
int		ft_atoi(const char *nptr);
char	*ft_strjoin_sp(char *s1, char *s2);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s);

//operations
void	swap_top(t_stack **stack);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	push(t_stack **stack_dest, t_stack **stack_src); //src -> dest.
void	pa(t_stack **stack_a, t_stack **stack_b); //b -> a
void	pb(t_stack **stack_b, t_stack **stack_a); //a -> b
void	rotate(t_stack **stack); //first -> last
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rev_rotate(t_stack **stack); //last -> first
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

//turk
void	sort_three_a(t_stack **stack);
void	sort_five_a(t_stack **stack_a, t_stack **stack_b);
void	sort_stacks(t_stack **stack_a, t_stack **stack_b);
t_stack	*max_stack_node(t_stack **stack);
int		max_stack(t_stack **stack);
t_stack	*min_stack_node(t_stack **stack);
int		min_stack(t_stack **stack);
t_stack	*get_cheapest_node(t_stack *stack);
void	build_sort_index_stack(t_stack **stack);
void	init_nodes(t_stack *stack_a, t_stack *stack_b);
void	set_index(t_stack *stack);
void	set_cost(t_stack *stack_a, t_stack *stack_b);
void	rr_to_top(t_stack **stack_a, t_stack **stack_b,
			t_stack *cheapest_node);
void	rrr_to_top(t_stack **stack_a, t_stack **stack_b,
			t_stack *cheapest_node);
void	finish_rotation_a(t_stack **stack_a, t_stack *top_node);
void	finish_rotation_b(t_stack **stack_b, t_stack *top_node);

#endif
