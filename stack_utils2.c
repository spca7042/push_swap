/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seralves <seralves@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:11:39 by seralves          #+#    #+#             */
/*   Updated: 2025/09/24 20:20:24 by seralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_bottom_node(t_stack *stack)
{
	t_stack	*bottom_node;

	if (!stack)
		return (NULL);
	bottom_node = stack;
	while (bottom_node && bottom_node->next)
		bottom_node = bottom_node->next;
	return (bottom_node);
}

int	min_stack(t_stack **stack)
{
	int		min;
	t_stack	*temp;

	if (stack == NULL || *stack == NULL)
		return (0);
	temp = *stack;
	min = INT_MAX;
	while (temp != NULL)
	{
		if (temp->num < min)
			min = temp->num;
		temp = temp->next;
	}
	return (min);
}

t_stack	*min_stack_node(t_stack **stack)
{
	int		min;
	t_stack	*temp;
	t_stack	*min_node;

	if (stack == NULL || *stack == NULL)
		return (0);
	temp = *stack;
	min = INT_MAX;
	while (temp != NULL)
	{
		if (temp->num < min)
		{
			min = temp->num;
			min_node = temp;
		}
		temp = temp->next;
	}
	return (min_node);
}

int	max_stack(t_stack **stack)
{
	int		max;
	t_stack	*temp;

	if (stack == NULL || *stack == NULL)
		return (0);
	temp = *stack;
	max = INT_MIN;
	while (temp != NULL)
	{
		if (temp->num > max)
			max = temp->num;
		temp = temp->next;
	}
	return (max);
}

t_stack	*max_stack_node(t_stack **stack)
{
	int		max;
	t_stack	*temp;
	t_stack	*max_node;

	if (stack == NULL || *stack == NULL)
		return (0);
	temp = *stack;
	max = INT_MIN;
	while (temp != NULL)
	{
		if (temp->num > max)
		{
			max = temp->num;
			max_node = temp;
		}
		temp = temp->next;
	}
	return (max_node);
}

/*# include <stdio.h> //printf
void	display_stack(t_stack *stack)
{
	while (stack)
	{
		printf("%d ", stack->num);
		stack = stack->next;
	}
	printf("\n");
	return ;
}*/

/*# include <stdio.h> //printf
void	display_stack_complete(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	printf("num           : ");
	while (temp)
	{
		printf("%d ", temp->num);
		temp = temp->next;
	}
	printf("\n");
	temp = stack;
	printf("index         : ");
	while (temp)
	{
		printf("%d ", temp->index);
		temp = temp->next;
	}
	printf("\n");
	temp = stack;
	printf("sort_index    : ");
	while (temp)
	{
		printf("%d ", temp->sort_index);
		temp = temp->next;
	}
	printf("\n");
	temp = stack;
	printf("cost          : ");
	while (temp)
	{
		printf("%d ", temp->cost);
		temp = temp->next;
	}
	printf("\n");
	temp = stack;
	printf("is_above_middle: ");
	while (temp)
	{
		printf("%d ", temp->is_above_middle);
		temp = temp->next;
	}
	printf("\n");
	temp = stack;
	printf("is_cheapest   : ");
	while (temp)
	{
		printf("%d ", temp->is_cheapest);
		temp = temp->next;
	}
	printf("\n");
	temp = stack;
	printf("target_node   : ");
	while (temp)
	{
		if (temp->target_node != NULL)
			printf("%d ", temp->target_node->sort_index);
		else
			printf("- ");
		temp = temp->next;
	}
	printf("\n");
	return ;
}*/