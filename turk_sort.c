/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seralves <seralves@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 18:55:11 by seralves          #+#    #+#             */
/*   Updated: 2025/09/24 17:36:55 by seralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest_node;

	if (*stack_b == NULL)
		return ;
	cheapest_node = get_cheapest_node(*stack_b);
	if (cheapest_node->target_node != NULL)
	{
		if (cheapest_node->is_above_middle
			&& cheapest_node->target_node->is_above_middle)
			rr_to_top(stack_a, stack_b, cheapest_node);
		else if (!(cheapest_node->is_above_middle)
			&& !(cheapest_node->target_node->is_above_middle))
			rrr_to_top(stack_a, stack_b, cheapest_node);
		finish_rotation_a(stack_a, cheapest_node->target_node);
	}
	finish_rotation_b(stack_b, cheapest_node);
	pa(stack_a, stack_b);
}

void	sort_five_a(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL || *stack_a == NULL)
		return ;
	while (stack_size(*stack_a) > 3)
	{
		init_nodes(*stack_a, *stack_b);
		finish_rotation_a(stack_a, min_stack_node(stack_a));
		pb(stack_b, stack_a);
	}
	sort_three_a(stack_a);
	while (stack_size(*stack_b) > 0)
		pa(stack_a, stack_b);
	return ;
}

void	sort_three_a(t_stack **stack_a)
{
	int	biggest;

	biggest = max_stack(stack_a);
	if ((*stack_a)->num == biggest)
		ra(stack_a);
	else if ((*stack_a)->next->num == biggest)
		rra(stack_a);
	if ((*stack_a)->num > (*stack_a)->next->num)
		sa(stack_a);
	return ;
}

void	init_send_to_b(t_stack **a, t_stack **b)
{
	int	sz_a;
	int	found_first;
	int	i;

	sz_a = stack_size(*a);
	found_first = 0;
	i = 0;
	while (found_first == 0 && i++ < sz_a)
	{
		if ((*a)->sort_index > sz_a / 30)
			pb(b, a);
		else
		{
			found_first = 1;
			ra(a);
		}
	}
	while (i++ < sz_a)
	{
		if ((*a)->sort_index > (get_bottom_node(*a))->sort_index
			&& (*a)->sort_index < (get_bottom_node(*a))->sort_index + sz_a / 15)
			ra(a);
		else
			pb(b, a);
	}
}

void	sort_stacks(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*smallest_node;
	int		size_a;

	if (*stack_a == NULL)
		return ;
	size_a = stack_size(*stack_a);
	build_sort_index_stack(stack_a);
	init_send_to_b(stack_a, stack_b);
	while (*stack_b != NULL)
	{
		init_nodes(*stack_a, *stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	set_index(*stack_a);
	smallest_node = min_stack_node(stack_a);
	if (smallest_node->is_above_middle)
		while (*stack_a != smallest_node)
			ra(stack_a);
	else
		while (*stack_a != smallest_node)
			rra(stack_a);
	return ;
}
