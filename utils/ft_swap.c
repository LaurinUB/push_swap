/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:54:20 by luntiet-          #+#    #+#             */
/*   Updated: 2022/11/10 10:37:17 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap_a(t_stack **stck)
{
	t_stack	*first;
	t_stack	*third;

	if (*stck && ft_getnode(*stck)->next)
	{
		first = *stck;
		*stck = first->next;
		third = ft_getnode(*stck)->next;
		first->next = third;
		ft_getnode(*stck)->next = first;
	}
}

void	ft_swap_b(t_stack **stck)
{
	t_stack	*first;
	t_stack	*third;

	if (*stck && ft_getnode(*stck)->next)
	{
		first = *stck;
		*stck = first->next;
		third = ft_getnode(*stck)->next;
		first->next = third;
		ft_getnode(*stck)->next = first;
	}
}

void	ft_swap(t_stack **astck, t_stack **bstck)
{
	ft_swap_a(astck);
	ft_swap_b(bstck);
}
