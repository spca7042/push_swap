/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_op_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seralves <seralves@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 19:28:40 by seralves          #+#    #+#             */
/*   Updated: 2025/09/28 16:58:58 by seralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_push_swap.h"

void	swap_top(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	return ;
}

void	sa(t_stack **stack_a)
{
	swap_top(stack_a);
	return ;
}

void	sb(t_stack **stack_b)
{
	swap_top(stack_b);
	return ;
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL
		|| *stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	swap_top(stack_a);
	swap_top(stack_b);
	return ;
}
