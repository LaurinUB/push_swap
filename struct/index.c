/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet <luntiet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:23:47 by luntiet-          #+#    #+#             */
/*   Updated: 2022/11/27 10:12:26 by luntiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_next_min(t_stack **stck)
{
	t_stack	*min;
	t_stack	*elmnt;
	int		has_min;

	has_min = 0;
	min = NULL;
	if (!*stck || !stck)
		return (NULL);
	elmnt = *stck;
	while (elmnt)
	{
		if (elmnt->index == -1 && (!has_min || elmnt->content < min->content))
		{
			min = elmnt;
			has_min = 1;
		}
		elmnt = elmnt->next;
	}
	return (min);
}

void	ft_set_index(t_stack **stck)
{
	t_stack	*elmnt;
	int		index;

	index = 0;
	elmnt = ft_next_min(stck);
	while (elmnt)
	{
		elmnt->index = index++;
		elmnt = ft_next_min(stck);
	}
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
