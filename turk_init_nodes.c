/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_init_nodes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seralves <seralves@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 20:37:07 by seralves          #+#    #+#             */
/*   Updated: 2025/09/23 16:36:33 by seralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_cheapest_node(t_stack *stack)
{
	t_stack	*curr_node;

	curr_node = stack;
	while (!curr_node->is_cheapest)
		curr_node = curr_node->next;
	return (curr_node);
}

static void	set_cheapest(t_stack *stack)
{
	int		best_match_value;
	t_stack	*best_match_node;
	t_stack	*curr_node;

	if (stack == NULL)
		return ;
	best_match_value = INT_MAX;
	curr_node = stack;
	while (curr_node != NULL)
	{
		curr_node->is_cheapest = 0;
		if (curr_node->cost < best_match_value)
		{
			best_match_value = curr_node->cost;
			best_match_node = curr_node;
		}
		curr_node = curr_node->next;
	}
	best_match_node->is_cheapest = 1;
	return ;
}

static void	set_target_node_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*curr_a_node;
	t_stack	*target_node_in_a;
	int		best_match_value;

	while (stack_b)
	{
		best_match_value = INT_MAX;
		curr_a_node = stack_a;
		while (curr_a_node)
		{
			if (stack_b != NULL && curr_a_node->sort_index > stack_b->sort_index
				&& curr_a_node->sort_index < best_match_value)
			{
				best_match_value = curr_a_node->sort_index;
				target_node_in_a = curr_a_node;
			}
			curr_a_node = curr_a_node->next;
		}
		if (best_match_value == INT_MAX)
			stack_b->target_node = min_stack_node(&stack_a);
		else
			stack_b->target_node = target_node_in_a;
		stack_b = stack_b->next;
	}
	return ;
}

void	set_index(t_stack *stack)
{
	int		i;
	int		middle;
	t_stack	*curr_node;

	if (stack == NULL)
		return ;
	i = 0;
	curr_node = stack;
	middle = stack_size(curr_node) / 2;
	while (curr_node != NULL)
	{
		curr_node->index = i;
		if (i < middle)
			curr_node->is_above_middle = 1;
		else
			curr_node->is_above_middle = 0;
		curr_node = curr_node->next;
		i++;
	}
	return ;
}

void	init_nodes(t_stack *stack_a, t_stack *stack_b)
{
	set_index(stack_a);
	set_index(stack_b);
	set_target_node_b(stack_a, stack_b);
	set_cost(stack_a, stack_b);
	set_cheapest(stack_b);
	return ;
}
