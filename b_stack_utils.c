/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_stack_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seralves <seralves@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:59:53 by seralves          #+#    #+#             */
/*   Updated: 2025/09/26 19:52:40 by seralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_push_swap.h"

t_stack	*create_new_node(int new_data)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->num = new_data;
	new_node->next = NULL;
	new_node->sort_index = -1;
	new_node->index = -1;
	new_node->cost = INT_MAX;
	new_node->is_above_middle = 0;
	new_node->is_cheapest = 0;
	new_node->target_node = NULL;
	return (new_node);
}

int	stack_size(t_stack *stack)
{
	int		size;
	t_stack	*node;

	if (stack == NULL)
		return (0);
	node = stack;
	size = 0;
	while (node != NULL)
	{
		node = node->next;
		size++;
	}
	return (size);
}

void	terminate_stack(t_stack	**stack)
{
	write(2, "Error\n", 6);
	free_stack(stack);
	return ;
}

void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*temp;

	if (stack == NULL || (*stack) == NULL)
		return ;
	current = *stack;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	*stack = NULL;
	return ;
}

int	stack_is_sorted(t_stack *stack)
{
	t_stack	*temp;

	if (stack == NULL)
		return (0);
	temp = stack;
	if (stack_size(temp) == 1)
		return (1);
	while (temp != NULL && temp->next != NULL)
	{
		if (temp->num > temp->next->num)
			return (0);
		temp = temp->next;
	}
	return (1);
}
