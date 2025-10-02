/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seralves <seralves@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:34:22 by seralves          #+#    #+#             */
/*   Updated: 2025/09/28 17:42:20 by seralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (1);
	if (argc >= 2)
		stack_a = process_arguments(argc, argv);
	if (!stack_is_sorted(stack_a))
	{
		if (stack_size(stack_a) == 1)
			;
		else if (stack_size(stack_a) == 2)
			sa(&stack_a);
		else if (stack_size(stack_a) == 3)
			sort_three_a(&stack_a);
		else if (stack_size(stack_a) == 4 || stack_size(stack_a) == 5)
			sort_five_a(&stack_a, &stack_b);
		else
			sort_stacks(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
