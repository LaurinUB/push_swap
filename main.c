/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:07:36 by luntiet-          #+#    #+#             */
/*   Updated: 2022/11/22 17:44:08 by luntiet-         ###   ########.fr       */
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
			else if (argv[i][j] == ' ')
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

t_stack	*ft_fill_from_string(t_stack *tmp, char **argv)
{
	int		i;
	char	**str;
	t_stack	*a;

	i = 0;
	str = ft_split(argv[1], ' ');
	if (!str)
		return (NULL);
	a = NULL;
	if (!argv)
		return (ft_putstr_fd("Error\n", 2), NULL);
	else
	{
		while (str[i])
		{
			if (ft_has_double(a, ft_atoi(str[i])))
				return (ft_putstr_fd("Error\n", 2), NULL);
			tmp = ft_stcknew(ft_atoi(str[i]));
			ft_stckadd_back(&a, tmp);
			i++;
		}
		return (a);
	}
}

t_stacks	*ft_init_stack(char **argv, int argc)
{
	int			i;
	t_stack		*a;
	t_stack		*tmp;

	tmp = NULL;
	a = NULL;
	if (argc == 2)
		a = ft_fill_from_string(tmp, argv);
	else
	{
		i = 1;
		while (i < argc)
		{
			if (ft_has_double(a, ft_atoi(argv[i])))
				return (ft_putstr_fd("Error\n", 2), NULL);
			tmp = ft_stcknew(ft_atoi(argv[i]));
			ft_stckadd_back(&a, tmp);
			i++;
		}
	}
	ft_set_index(&a);
	return (ft_newstacks(a));
}

int	main(int argc, char **argv)
{
	t_stacks	*stck;

	if (argc < 1 || !ft_is_int(argv))
	{
		return (ft_putstr_fd("Error\n", 2), 0);
	}
	if (argc > 1)
	{
		stck = ft_init_stack(argv, argc);
		if (!stck)
			return (0);
		//ft_teststacks(&stck->a, &stck->b);
		ft_sort(stck);
		//ft_printindex(stck->b);
	}
	return (0);
}
