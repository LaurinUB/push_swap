/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:07:36 by luntiet-          #+#    #+#             */
/*   Updated: 2022/12/16 11:32:27 by luntiet-         ###   ########.fr       */
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

t_stack	*fill_from_string(t_stack *tmp, char *argv, t_stack *a)
{
	int		i;
	char	**str;

	i = 0;
	str = ft_split(argv, ' ');
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (has_double(a, ft_atoi(str[i])))
			return (splitnstck_free(a, str), ft_putstr_fd("Error\n", 2), NULL);
		tmp = stck_new(ft_atoi(str[i]));
		if (!tmp)
			return (splitnstck_free(a, str), NULL);
		stckadd_back(&a, tmp);
		i++;
	}
	return (splitfree(str), a);
}

t_stacks	*init_stack(char **argv, t_stacks *stck, t_stack *a)
{
	t_stack	*tmp;
	char	*str;
	int		i;

	i = 1;
	tmp = NULL;
	if (!*argv)
		return (ft_putstr_fd("Error\n", 2), NULL);
	str = NULL;
	while (argv[i])
	{
		str = ft_strjoin_gnl(str, argv[i]);
		str = ft_strjoin_gnl(str, " ");
		i++;
	}
	a = fill_from_string(tmp, str, a);
	set_index(&a);
	stck = new_stacks(a);
	return (free (str), stck);
}

int	main(int argc, char **argv)
{
	t_stacks	*stck;
	t_stack		*a;

	stck = NULL;
	a = NULL;
	if (!argv || !is_int(argv))
		return (ft_putstr_fd("Error\n", 2), 0);
	if (argc > 1)
	{
		stck = init_stack(argv, stck, a);
		if (!stck)
			return (free(stck), 0);
		if (is_sorted(stck->a))
			return (stackfree(stck), 0);
		sort(stck);
		stackfree(stck);
	}
	return (0);
}
