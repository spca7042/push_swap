/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seralves <seralves@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 19:28:40 by seralves          #+#    #+#             */
/*   Updated: 2025/09/28 16:59:13 by seralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	swap_top(stack_a);
	write(1, "sa\n", 3);
	return ;
}

void	sb(t_stack **stack_b)
{
	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	swap_top(stack_b);
	write(1, "sb\n", 3);
	return ;
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL
		|| *stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	swap_top(stack_a);
	swap_top(stack_b);
	write(1, "ss\n", 3);
	return ;
}
