/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seralves <seralves@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 21:47:38 by seralves          #+#    #+#             */
/*   Updated: 2025/09/26 13:07:14 by seralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_push_swap.h"
#include "get_next_line.h"

void	apply_operations(t_stack **stack_a, t_stack **stack_b, char	*line)
{
	if (ft_stcp(line, "sa\n") == 0)
		sa(stack_a);
	else if (ft_stcp(line, "sb\n") == 0)
		sb(stack_b);
	else if (ft_stcp(line, "pa\n") == 0)
		pa(stack_a, stack_b);
	else if (ft_stcp(line, "pb\n") == 0)
		pb(stack_b, stack_a);
	else if (ft_stcp(line, "ra\n") == 0)
		ra(stack_a);
	else if (ft_stcp(line, "rb\n") == 0)
		rb(stack_b);
	else if (ft_stcp(line, "rr\n") == 0)
		rr(stack_a, stack_b);
	else if (ft_stcp(line, "rra\n") == 0)
		rra(stack_a);
	else if (ft_stcp(line, "rrb\n") == 0)
		rrb(stack_b);
	else if (ft_stcp(line, "rrr\n") == 0)
		rrr(stack_a, stack_b);
	return ;
}

int	read_operations(t_stack **stack_a, t_stack **stack_b)
{
	struct s_iter	it;

	it.value = 1;
	while (it.value)
	{
		it.l = get_next_line(0);
		if (it.l == NULL || ft_stcp(it.l, "\n") == 0 || ft_stcp(it.l, "") == 0)
			it.value = 0;
		else if (ft_stcp(it.l, "sa\n") == 0 || ft_stcp(it.l, "sb\n") == 0
			|| ft_stcp(it.l, "pa\n") == 0 || ft_stcp(it.l, "pb\n") == 0
			|| ft_stcp(it.l, "ra\n") == 0 || ft_stcp(it.l, "rb\n") == 0
			|| ft_stcp(it.l, "rr\n") == 0 || ft_stcp(it.l, "rra\n") == 0
			|| ft_stcp(it.l, "rrb\n") == 0 || ft_stcp(it.l, "rrr\n") == 0)
			apply_operations(stack_a, stack_b, it.l);
		else
		{
			write(2, "Error\n", 6);
			it.value = 0;
			free(it.l);
			return (0);
		}
		free (it.l);
	}
	close (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		rd;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2 || (argc == 2 && argv[1][0] == '\0'))
		return (1);
	if (argc >= 2)
		stack_a = process_arguments(argc, argv);
	if (stack_a == NULL)
		return (0);
	rd = read_operations(&stack_a, &stack_b);
	if (rd == 1)
	{
		if (stack_a != NULL && stack_b == NULL && stack_is_sorted(stack_a))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	if (stack_a != NULL)
		free_stack(&stack_a);
	if (stack_b != NULL)
		free_stack(&stack_b);
	return (0);
}
