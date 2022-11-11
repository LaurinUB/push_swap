/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:07:36 by luntiet-          #+#    #+#             */
/*   Updated: 2022/11/11 16:06:14 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_int(char **argv)
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

static int	ft_fill_from_string(t_stack **astck, t_stack *tmp, char **argv)
{
	int		i;
	char	**str;
	long	current;

	i = 0;
	str = ft_split(argv[1], ' ');
	current = 0;
	if (!astck || !argv)
	{
		ft_printf("Error\n");
		return (0);
	}
	else
	{
		while (str[i])
		{
			current = ft_atoi(str[i]);
			tmp = ft_stcknew(current);
			ft_stckadd_back(astck, tmp);
			i++;
		}
		return (1);
	}
}

static int	ft_init_stack(t_stack **astck, char **argv, int argc)
{
	int		i;
	t_stack	*tmp;

	tmp = NULL;
	if (argc == 2)
		return (ft_fill_from_string(astck, tmp, argv));
	else
	{
		i = 1;
		while (i < argc)
		{
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

	astck = (t_stack **)malloc(sizeof(t_stack **));
	if (!astck)
		return (0);
	bstck = (t_stack **)malloc(sizeof(t_stack **));
	if (!bstck)
		return (0);
	if (argc < 1 || !ft_is_int(argv))
	{
		ft_printf("Error\n");
		return (0);
	}
	if (argc > 1)
	{
		if (!ft_init_stack(astck, argv, argc))
			return (free(astck), free(bstck), 0);
		ft_set_index(astck);
	}
	return (0);
}
