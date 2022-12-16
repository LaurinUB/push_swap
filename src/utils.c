/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 10:49:50 by luntiet           #+#    #+#             */
/*   Updated: 2022/12/16 11:28:51 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_input(char *argv)
{
	int		j;
	char	*arg;

	j = 0;
	arg = ft_strtrim(argv, " ");
	if (!arg)
		return (free(arg), 0);
	while (arg[j])
	{
		if (ft_isdigit(arg[j]))
			j++;
		else if (arg[j] == '-' && ft_isdigit(arg[j + 1]))
			j++;
		else if (arg[j] == '+' && ft_isdigit(arg[j + 1]))
			j++;
		else if (arg[j] == ' ')
			j++;
		else
			return (free(arg), 0);
	}
	return (free(arg), 1);
}

int	is_int(char **argv)
{
	int	i;

	i = 1;
	if (!*argv)
		return (0);
	while (argv[i])
	{
		if (!check_input(argv[i]))
			return (0);
		if (ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i]) < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

void	splitfree(char **str)
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

void	stackfree(t_stacks *stck)
{
	stckclear(stck->a);
	free(stck);
}

void	splitnstck_free(t_stack *a, char **split)
{
	splitfree(split);
	stckclear(a);
}
