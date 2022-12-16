/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 10:49:50 by luntiet           #+#    #+#             */
/*   Updated: 2022/12/16 16:56:20 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	has_double(t_stack *stck, int nbr)
{
	t_stack	*tmp;

	if (!stck)
		return (0);
	tmp = stck;
	while (tmp)
	{
		if (tmp->content == nbr)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

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

static int	check_int_max(char *argv)
{
	int		i;
	char	**arg;

	i = 0;
	if (!argv)
		return (0);
	arg = ft_split(argv, ' ');
	if (!arg[i])
		return (splitfree(arg), 0);
	while (arg[i])
	{
		if (ft_atol(arg[i]) > INT_MAX || ft_atol(arg[i]) < INT_MIN)
			return (splitfree(arg), 0);
		i++;
	}
	return (splitfree(arg), 1);
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
		if (!check_int_max(argv[i]))
			return (0);
		i++;
	}
	return (1);
}
