/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seralves <seralves@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:40:04 by seralves          #+#    #+#             */
/*   Updated: 2025/09/23 16:03:11 by seralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_to_top(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest_node)
{
	if (*stack_a == NULL || *stack_b == NULL || cheapest_node == NULL
		|| cheapest_node->target_node == NULL)
		return ;
	while ((*stack_b) != cheapest_node
		&& (*stack_a) != cheapest_node->target_node)
		rr(stack_a, stack_b);
	set_index(*stack_a);
	set_index(*stack_b);
	return ;
}

void	rrr_to_top(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest_node)
{
	if (*stack_a == NULL || *stack_b == NULL || cheapest_node == NULL
		|| cheapest_node->target_node == NULL)
		return ;
	while ((*stack_a) != cheapest_node->target_node
		&& (*stack_b) != cheapest_node)
		rrr(stack_a, stack_b);
	set_index(*stack_a);
	set_index(*stack_b);
	return ;
}

void	finish_rotation_a(t_stack **stack_a, t_stack *top_node)
{
	while (*stack_a != top_node)
	{
		if (top_node->is_above_middle)
			ra(stack_a);
		else
			rra(stack_a);
	}
	return ;
}

void	finish_rotation_b(t_stack **stack_b, t_stack *top_node)
{
	while (*stack_b != top_node)
	{
		if (top_node->is_above_middle)
			rb(stack_b);
		else
			rrb(stack_b);
	}
	return ;
}
