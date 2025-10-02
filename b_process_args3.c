/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_process_args3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seralves <seralves@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 22:02:18 by seralves          #+#    #+#             */
/*   Updated: 2025/09/25 19:44:48 by seralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_push_swap.h"

void	free_split_str(char **str)
{
	int	i;

	i = -1;
	while (str[++i] != NULL)
		free(str[i]);
	free(str);
	return ;
}

int	has_no_chars_except_spaces(char *str)
{
	size_t	i;
	int		is_not_space;

	if (str == NULL)
		return (0);
	if (ft_stcp(str, "") == 0)
		return (1);
	i = 0;
	is_not_space = 0;
	while (str[i])
	{
		if (str[i] != ' ' && !(str[i] >= 9 && (str[i] <= 13)))
			is_not_space = 1;
		i++;
	}
	if (is_not_space == 0)
		return (1);
	return (0);
}
