/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet <luntiet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:07:36 by luntiet-          #+#    #+#             */
/*   Updated: 2022/11/27 10:23:48 by luntiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_int(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]))
				j++;
			else if (argv[i][j] == '-' && ft_isdigit(argv[i][j + 1]))
				j++;
			else if (argv[1][j] == ' ')
				j++;
			else
				return (0);
		}
		j = 0;
		i++;
	}
	return (1);
}

int	ft_has_double(t_stack *stck, int nbr)
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

t_stack	*ft_fill_from_string(t_stack *tmp, char **argv, t_stack *a)
{
	int		i;
	char	**str;

	i = 0;
	if (!argv || !*argv || !**argv)
		return (ft_putstr_fd("Error\n", 2), NULL);
	else
	{
		str = ft_split(argv[1], ' ');
		if (!str)
			return (NULL);
		while (str[i])
		{
			if (ft_has_double(a, ft_atoi(str[i])))
				return (ft_splitfree(str), ft_stckclear(a), ft_putstr_fd("Error\n", 2), NULL);
			tmp = ft_stcknew(ft_atoi(str[i]));
			if (!tmp)
				return (ft_stckclear(a), NULL);
			ft_stckadd_back(&a, tmp);
			i++;
		}
		ft_splitfree(str);
		return (a);
	}
}

t_stacks	*ft_init_stack(char **argv, int argc, t_stacks *stck, t_stack *a)
{
	int			i;
	t_stack		*tmp;

	tmp = NULL;
	if (argc == 2 && argv[1])
		a = ft_fill_from_string(tmp, argv, a);
	else
	{
		i = 1;
		while (i < argc && argv[i])
		{
			if (ft_has_double(a, ft_atoi(argv[i])))
				return (ft_stckclear(a), ft_putstr_fd("Error\n", 2), NULL);
			tmp = ft_stcknew(ft_atoi(argv[i]));
			if (!tmp)
				return (ft_stckclear(a), NULL);
			ft_stckadd_back(&a, tmp);
			i++;
		}
	}
	ft_set_index(&a);
	stck = ft_newstacks(a);
	return (stck);
}

int	main(int argc, char **argv)
{
	t_stacks	*stck;
	t_stack		*a;

	stck = NULL;
	a = NULL;
	if (!argv || argc <= 1 || !ft_is_int(argv) || !ft_range(argv))
	{
		return (ft_putstr_fd("Error\n", 2), 0);
	}
	if (argc > 1 && *argv[1])
	{
		stck = ft_init_stack(argv, argc, stck, a);
		if (!stck)
			return (free(stck), 0);
		if (ft_is_sorted(stck->a))
			return (free(stck), ft_stckclear(stck->a), 0);
		ft_sort(stck);
		ft_stckclear(stck->a);
		free(stck);
	}
	//TODO FINDE WHERE THE LIST TAILING IS LOST AT OPERATIONS YOU MUNK
	//system("leaks push_swap");
	return (0);
}