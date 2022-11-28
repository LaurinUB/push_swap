/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:53:38 by luntiet-          #+#    #+#             */
/*   Updated: 2022/11/28 09:57:03 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_is_sorted(t_stack *stck)
{
	if (!stck)
		return (1);
	while (stck->next && stck)
	{
		if (stck->index > stck->next->index)
			return (0);
		else
			stck = stck->next;
	}
	return (1);
}

int	ft_is_rev_sorted(t_stack *stck)
{
	if (!stck)
		return (1);
	while (stck->next && stck)
	{
		if (stck->index < stck->next->index)
			return (0);
		else
			stck = stck->next;
	}
	return (1);
}