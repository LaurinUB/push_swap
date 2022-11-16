/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:07:36 by luntiet-          #+#    #+#             */
/*   Updated: 2022/11/16 19:26:54 by luntiet-         ###   ########.fr       */
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

int	ft_has_double(t_stack **stck, int nbr)
{
	t_stack	*tmp;

	if (!stck)
		return (0);
	tmp = *stck;
	while (tmp)
	{
		if (tmp->content == nbr)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_fill_from_string(t_stack **astck, t_stack *tmp, char **argv)
{
	int		i;
	char	**str;

	i = 0;
	str = ft_split(argv[1], ' ');
	if (!astck || !argv)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	else
	{
		while (str[i])
		{
			if (ft_has_double(astck, ft_atoi(str[i])))
			{
				ft_putstr_fd("Error\n", 2);
				return (0);
			}
			tmp = ft_stcknew(ft_atoi(str[i]));
			ft_stckadd_back(astck, tmp);
			i++;
		}
		return (1);
	}
}

int	ft_init_stack(t_stack **astck, char **argv, int argc)
{
	int		i;
	t_stack	*tmp;

	tmp = malloc(sizeof(t_stack));
	if (argc == 2)
		return (ft_fill_from_string(astck, tmp, argv));
	else
	{
		i = 1;
		while (i < argc)
		{
			if (ft_has_double(astck, ft_atoi(argv[i])))
			{
				ft_putstr_fd("Error\n", 2);
				return (0);
			}
			tmp = ft_stcknew(ft_atoi(argv[i]));
			ft_stckadd_back(astck, tmp);
			i++;
		}
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	**astck;
	t_stack	**bstck;

	astck = malloc(sizeof(t_stack *));
	if (!astck)
		return (0);
	bstck = malloc(sizeof(t_stack *));
	if (!bstck)
		return (0);
	*astck = NULL;
	*bstck = NULL;
	if (argc < 1 || !ft_is_int(argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (argc > 1)
	{
		if (!ft_init_stack(astck, argv, argc))
			return (free(astck), free(bstck), 0);
		ft_set_index(astck);
		ft_sort(astck, bstck);
		//ft_teststacks(astck, bstck);
		//ft_printstcks(*astck, *bstck);
		//ft_printf("\n");
		ft_printindex(*bstck);
	}
	return (0);
}
