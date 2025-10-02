/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seralves <seralves@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 19:32:46 by seralves          #+#    #+#             */
/*   Updated: 2025/09/23 16:37:05 by seralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Take the first element at the top of src and put it at the top of dest.
void	push(t_stack **dest, t_stack **src)
{
	t_stack	*temp;

	if (!src || !*src)
		return ;
	temp = *src;
	*src = (*src)->next;
	temp->next = *dest;
	*dest = temp;
	return ;
}

//(push a): Take the first element at the top of b and put it at the top of a.
void	pa(t_stack **a, t_stack **b)
{
	if (!b || !*b)
		return ;
	push(a, b);
	write(1, "pa\n", 3);
	return ;
}

//(push b): Take the first element at the top of a and put it at the top of b.
void	pb(t_stack **b, t_stack **a)
{
	if (!a || !*a)
		return ;
	push(b, a);
	write(1, "pb\n", 3);
	return ;
}
