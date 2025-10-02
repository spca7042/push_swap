/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_args2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seralves <seralves@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 20:58:13 by seralves          #+#    #+#             */
/*   Updated: 2025/09/24 21:06:54 by seralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_overflow(char *str)
{
	if (ft_atol(str) < INT_MIN || ft_atol(str) > INT_MAX)
		return (1);
	else
		return (0);
}

int	has_invalid_syntax(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '-' || str[i] == '+')
			&& (!str[i + 1] || str[i + 1] < '0' || str[i + 1] > '9'))
			return (1);
		else if ((str[i] < '0' || str[i] > '9')
			&& !(str[i] == '-' || str[i] == '+'))
			return (1);
		i++;
	}
	return (0);
}

int	is_valid_arg(char *str)
{
	if (has_invalid_syntax(str) || has_overflow(str))
		return (0);
	else
		return (1);
}

int	has_repeated_args(char **split_str)
{
	struct s_iter	it;

	if (split_str == NULL)
		return (0);
	it.i = 0;
	it.j = 1;
	while (split_str[it.i] != NULL && split_str[it.j] != NULL)
	{
		while (split_str[it.i] != NULL)
		{
			while (split_str[it.j] != NULL
				&& ft_atoi(split_str[it.i]) != ft_atoi(split_str[it.j]))
				it.j++;
			if (split_str[it.j] != NULL
				&& ft_atoi(split_str[it.i]) == ft_atoi(split_str[it.j]))
				return (1);
			it.i++;
			if (split_str[it.i] != NULL)
				it.j = it.i + 1;
		}
	}
	return (0);
}

int	is_valid_split(char **split_str)
{
	size_t	i;

	i = 0;
	while (split_str[i])
	{
		if (!is_valid_arg(split_str[i]))
			return (0);
		i++;
	}
	if (has_repeated_args(split_str))
		return (0);
	return (1);
}
