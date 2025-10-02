/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_utils2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seralves <seralves@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:49:14 by seralves          #+#    #+#             */
/*   Updated: 2025/09/25 19:43:13 by seralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_push_swap.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	number;
	int	sign;

	i = 0;
	number = 0;
	sign = 1;
	if (!*nptr)
		return (0);
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		if (number > INT_MAX / 10)
			return (INT_MAX * sign);
		number = 10 * number + nptr[i++] - '0';
	}
	return (number * sign);
}

long	ft_atol(const char *nptr)
{
	int		i;
	long	number;
	int		sign;

	i = 0;
	number = 0;
	sign = 1;
	if (!*nptr)
		return (0);
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		if (number > LONG_MAX / 10)
			return (LONG_MAX * sign);
		number = 10 * number + nptr[i++] - '0';
	}
	return (number * sign);
}

char	*ft_strjoin_sp(char *s1, char *s2)
{
	char	*joined_str;
	ssize_t	i;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	joined_str = malloc((len1 + len2 + 2) * sizeof(char));
	if (!joined_str)
		return (NULL);
	i = -1;
	while (++i < (ssize_t)len1)
		joined_str[i] = s1[i];
	joined_str[i++] = ' ';
	while ((size_t)i < len1 + len2 + 1)
	{
		joined_str[i] = s2[i - 1 - len1];
		i++;
	}
	joined_str[i] = '\0';
	free (s1);
	return (joined_str);
}

int	ft_stcp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
		i++;
	}
	return (0);
}
