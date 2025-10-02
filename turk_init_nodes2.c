/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_init_nodes2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seralves <seralves@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:15:49 by seralves          #+#    #+#             */
/*   Updated: 2025/09/24 15:53:30 by seralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_cost(t_stack *stack_a, t_stack *stack_b)
{
	int		size_a;
	int		size_b;
	t_stack	*curr_b;
	t_stack	*curr_a;

	size_a = stack_size(stack_a);
	size_b = stack_size(stack_b);
	curr_a = stack_a;
	curr_b = stack_b;
	while (curr_b)
	{
		if (!(curr_b->is_above_middle))
			curr_b->cost = size_b - curr_b->index;
		else
			curr_b->cost = curr_b->index;
		if (curr_b->target_node != NULL)
		{
			if (curr_b->target_node->is_above_middle)
				curr_b->cost += curr_b->target_node->index;
			else
				curr_b->cost += size_a - curr_b->target_node->index;
		}
		curr_b = curr_b->next;
	}
	return ;
}
