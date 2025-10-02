/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seralves <seralves@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 19:29:34 by seralves          #+#    #+#             */
/*   Updated: 2025/09/28 16:59:09 by seralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//(reverse rotate): Shift down all elements of stack by 1. 
//The last element becomes the first one.
void	rev_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*temp;

	if (!*stack || !(*stack)->next)
		return ;
	if (!(*stack)->next->next)
	{
		swap_top(stack);
		return ;
	}
	first = *stack;
	last = first->next;
	while (last->next->next != NULL)
		last = last->next;
	temp = last->next;
	last->next = NULL;
	temp->next = first;
	*stack = temp;
	return ;
}

//(reverse rotate a): Shift down all elements of stack a by 1. 
//The last element becomes the first one.
void	rra(t_stack **stack_a)
{
	if (!*stack_a || !(*stack_a)->next)
		return ;
	rev_rotate(stack_a);
	write(1, "rra\n", 4);
	return ;
}

//rrb (reverse rotate b): Shift down all elements of stack b by 1. 
//The last element becomes the first one.
void	rrb(t_stack **stack_b)
{
	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	rev_rotate(stack_b);
	write(1, "rrb\n", 4);
	return ;
}

//rrr : rra and rrb at the same time
void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL
		|| *stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	write(1, "rrr\n", 4);
	return ;
}
