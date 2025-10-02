/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_process_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seralves <seralves@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 21:10:26 by seralves          #+#    #+#             */
/*   Updated: 2025/09/25 19:45:13 by seralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_push_swap.h"

void	terminate_stack_split(t_stack **stack, char **str)
{
	write(2, "Error\n", 6);
	free_stack(stack);
	free_split_str(str);
	return ;
}

static void	build_stack(t_stack *stack, char **split_str)
{
	size_t	i;
	t_stack	*new_node;
	t_stack	*last_node;

	last_node = stack;
	i = 0;
	while (split_str[++i] != NULL)
	{
		if (is_valid_arg(split_str[i]))
		{
			new_node = create_new_node(ft_atoi(split_str[i]));
			last_node->next = new_node;
			last_node = last_node->next;
		}
		else
		{
			terminate_stack_split(&stack, split_str);
			return ;
		}
	}
	if (split_str[i] && !is_valid_arg(split_str[i]))
		terminate_stack_split(&stack, split_str);
	free_split_str(split_str);
	return ;
}

t_stack	*process_arguments_string(char *str)
{
	size_t	i;
	t_stack	*stack;
	char	**split_str;

	i = 0;
	split_str = ft_split(str, ' ');
	if (!split_str)
		free_split_str(split_str);
	if (!is_valid_split(split_str))
	{
		free_split_str(split_str);
		write(2, "Error\n", 6);
		return (NULL);
	}
	if (split_str[i] && is_valid_arg(split_str[i]))
		stack = create_new_node(ft_atoi(split_str[i]));
	else
	{
		free_split_str(split_str);
		write(2, "Error\n", 6);
		return (NULL);
	}
	build_stack(stack, split_str);
	return (stack);
}

char	*join_argv(int argc, char **argv)
{
	struct s_iter	it;

	it.i = 1;
	if (has_no_chars_except_spaces(argv[1]))
		it.str1 = ft_strdup("E");
	else
		it.str1 = ft_strdup(argv[1]);
	while (++it.i < argc)
	{
		if (has_no_chars_except_spaces(argv[it.i]))
			it.str2 = ft_strjoin_sp(it.str1, "E");
		else
			it.str2 = ft_strjoin_sp(it.str1, argv[it.i]);
		it.str1 = it.str2;
	}
	return (it.str1);
}

t_stack	*process_arguments(int argc, char **argv)
{
	char	*str;
	t_stack	*stack;

	stack = NULL;
	str = join_argv(argc, argv);
	stack = process_arguments_string(str);
	free(str);
	return (stack);
}
