/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_op_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seralves <seralves@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 19:28:20 by seralves          #+#    #+#             */
/*   Updated: 2025/09/28 16:58:52 by seralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_push_swap.h"

// Shift up all elements of stack by 1. 
//The first element becomes the last one.
void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = (*stack)->next;
	last = first->next;
	while (last->next != NULL)
		last = last->next;
	if (last->next == NULL)
		last->next = first;
	first->next = NULL;
	return ;
}

//(rotate a): Shift up all elements of stack a by 1. 
//The first element becomes the last one.
void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	return ;
}

//(rotate b): Shift up all elements of stack b by 1. 
//The first element becomes the last one.
void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	return ;
}

//ra and rb at the same time.
void	rr(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL
		|| *stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	rotate(stack_a);
	rotate(stack_b);
	return ;
}
