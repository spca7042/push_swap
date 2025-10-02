/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_op_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seralves <seralves@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 19:32:46 by seralves          #+#    #+#             */
/*   Updated: 2025/09/25 19:41:51 by seralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_push_swap.h"

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
	return ;
}

//(push b): Take the first element at the top of a and put it at the top of b.
void	pb(t_stack **b, t_stack **a)
{
	if (!a || !*a)
		return ;
	push(b, a);
	return ;
}
