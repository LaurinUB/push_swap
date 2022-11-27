/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet <luntiet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:11:59 by luntiet-          #+#    #+#             */
/*   Updated: 2022/11/27 10:48:46 by luntiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_first_top(t_stacks *stck, int max)
{
	t_stack	*tmp;

	tmp = stck->a;
	while (!(tmp->index <= max))
	{
		tmp = tmp->next;
	}
	return (tmp->index);
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
