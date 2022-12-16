/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:23:47 by luntiet-          #+#    #+#             */
/*   Updated: 2022/12/16 10:29:05 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*next_min(t_stack **stck)
{
	t_stack	*min;
	t_stack	*elmnt;
	int		has_min;

	has_min = 0;
	min = NULL;
	if (!*stck || !stck)
		return (NULL);
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

void	set_index(t_stack **stck)
{
	t_stack	*elmnt;
	int		index;

	index = 0;
	elmnt = next_min(stck);
	while (elmnt)
	{
		elmnt->index = index++;
		elmnt = next_min(stck);
	}
}
