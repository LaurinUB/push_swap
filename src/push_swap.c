/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:07:36 by luntiet-          #+#    #+#             */
/*   Updated: 2022/11/30 16:16:06 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_is_int(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!argv[i] || !argv[i][0])
			return (0);
		if (!ft_check(argv[i], 0))
			return (0);
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

t_stack	*ft_fill_from_string(t_stack *tmp, char *argv, t_stack *a)
{
	int		i;
	char	**str;

	i = 0;
	str = ft_split(argv, ' ');
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (ft_has_double(a, ft_atoi(str[i])))
			return (ft_splitfree(str),
				ft_stckclear(a),
				ft_putstr_fd("Error\n", 2), NULL);
		tmp = ft_stcknew(ft_atoi(str[i]));
		if (!tmp)
			return (ft_stckclear(a), NULL);
		ft_stckadd_back(&a, tmp);
		i++;
	}
	return (ft_splitfree(str), a);
}

t_stacks	*ft_init_stack(char **argv, t_stacks *stck, t_stack *a)
{
	t_stack	*tmp;
	char	*str;
	int		i;

	i = 1;
	tmp = NULL;
	if (!*argv)
		return (ft_putstr_fd("Error\n", 2), NULL);
	str = ft_strdup(argv[i++]);
	while (argv[i])
	{
		str = ft_strjoin(str, " ");
		str = ft_strjoin(str, argv[i]);
		i++;
	}
	a = ft_fill_from_string(tmp, str, a);
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
	if (!argv || !ft_is_int(argv) || !ft_range(argv))
	{
		return (ft_putstr_fd("Error\n", 2), 0);
	}
	if (argc > 1 && *argv[1])
	{
		stck = ft_init_stack(argv, stck, a);
		if (!stck)
			return (free(stck), 0);
		if (ft_is_sorted(stck->a))
			return (free(stck), ft_stckclear(stck->a), 0);
		ft_sort(stck);
		ft_stckclear(stck->a);
		free(stck);
	}
	return (0);
}
