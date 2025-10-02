/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_indexing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seralves <seralves@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:36:45 by seralves          #+#    #+#             */
/*   Updated: 2025/09/22 17:38:22 by seralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_unindexed_stack(t_stack **stack)
{
	int		min;
	t_stack	*temp;

	if (stack == NULL || *stack == NULL)
		return (0);
	temp = *stack;
	min = INT_MAX;
	while (temp != NULL)
	{
		if (temp->num < min && temp->sort_index == -1)
			min = temp->num;
		temp = temp->next;
	}
	return (min);
}

int	is_part_unindexed(t_stack **stack)
{
	int		sort_indexed;
	t_stack	*temp;

	if (stack == NULL || *stack == NULL)
		return (0);
	temp = *stack;
	sort_indexed = 0;
	while (temp != NULL)
	{
		if (temp->sort_index == -1)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	apply_sort_index(t_stack **stack, int min_unindexed, int sort_index)
{
	t_stack	*temp;

	if (stack == NULL || *stack == NULL)
		return (0);
	temp = *stack;
	while (temp != NULL)
	{
		if (temp->num == min_unindexed && temp->sort_index == -1)
		{
			temp->sort_index = sort_index;
			return (1);
		}
		temp = temp->next;
	}
	return (0);
}

void	build_sort_index_stack(t_stack **stack)
{
	int		sort_index;
	int		min_unindexed;
	int		is_sort_indexed;

	if (stack == NULL || *stack == NULL)
		return ;
	sort_index = 0;
	is_sort_indexed = 1;
	while (is_part_unindexed(stack) && is_sort_indexed)
	{
		min_unindexed = min_unindexed_stack(stack);
		is_sort_indexed = apply_sort_index(stack, min_unindexed, sort_index);
		sort_index++;
	}
	return ;
}
