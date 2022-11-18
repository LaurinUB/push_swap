/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:54:20 by luntiet-          #+#    #+#             */
/*   Updated: 2022/11/14 11:55:56 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap_a(t_stack **stck)
{
	t_stack	*first;
	t_stack	*third;

	if (*stck && (*stck)->next)
	{
		first = *stck;
		*stck = first->next;
		third = (*stck)->next;
		first->next = third;
		(*stck)->next = first;
	}
}

void	ft_swap_b(t_stack **stck)
{
	t_stack	*first;
	t_stack	*third;

	if (*stck && (*stck)->next)
	{
		first = *stck;
		*stck = first->next;
		third = (*stck)->next;
		first->next = third;
		(*stck)->next = first;
	}
}

void	ft_swap(t_stack **astck, t_stack **bstck)
{
	if (*astck && *bstck)
	{
		ft_swap_a(astck);
		ft_swap_b(bstck);
	}
	else if (*astck && !*bstck)
		ft_swap_a(astck);
	else if (!*astck && *bstck)
		ft_swap_b(bstck);
}
