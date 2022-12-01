/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 10:49:50 by luntiet           #+#    #+#             */
/*   Updated: 2022/12/01 13:49:32 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_check(char *argv, int j)
{
	int	t;

	t = 0;
	argv = ft_strtrim(argv, " ");
	if (!*argv)
		return (0);
	while (argv[j])
	{
		if (ft_isdigit(argv[j]))
			j++;
		else if (argv[j] == '-' && ft_isdigit(argv[j + 1]))
			j++;
		else if (argv[j] == '+' && ft_isdigit(argv[j + 1]))
			j++;
		else if (argv[j] == ' ')
			j++;
		else
			return (0);
	}
	return (1);
}

long	ft_atol(char *str)
{
	long	n;
	int		sign;

	n = 0;
	sign = 1;
	if (!str)
		return (0);
	while (*str == ' ' || *str == '\t' || *str == '\r' \
		|| *str == '\n' || *str == '\v' || *str == '\f')
		str++;
	if ((*str == '+' || *str == '-'))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		n = 10 * n + (*str - '0');
		str++;
	}
	return (n * sign);
}

int	ft_range(char **argv)
{
	int	i;

	i = 0;
	if (!*argv)
		return (0);
	while (argv[i])
	{
		if (ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i]) < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

void	ft_splitfree(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
