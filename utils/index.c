/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:23:47 by luntiet-          #+#    #+#             */
/*   Updated: 2022/11/12 11:24:05 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_is_sorted(t_stack *astck)
{
	while (astck->next && astck)
	{
		if (astck->index > astck->next->index)
			return (0);
		else
			astck = astck->next;
	}
	return (1);
}

static t_stack	*ft_next_min(t_stack **stck)
{
	t_stack	*min;
	t_stack	*elmnt;
	int		has_min;

	has_min = 0;
	min = NULL;
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
