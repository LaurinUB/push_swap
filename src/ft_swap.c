/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:54:20 by luntiet-          #+#    #+#             */
/*   Updated: 2022/12/16 10:46:20 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(t_stack **stck)
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
		ft_printf("sa\n");
	}
}

void	swap_b(t_stack **stck)
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
		ft_printf("sb\n");
	}
}

void	swap(t_stack **astck, t_stack **bstck)
{
	t_stack	*first;
	t_stack	*third;

	if (astck && (*astck)->next && bstck && (*bstck)->next)
	{
		first = *astck;
		*astck = first->next;
		third = (*astck)->next;
		first->next = third;
		(*astck)->next = first;
		first = *bstck;
		*bstck = first->next;
		third = (*bstck)->next;
		first->next = third;
		(*bstck)->next = first;
		ft_printf("ss\n");
	}
	else if (astck && (*astck)->next && !*bstck)
		swap_a(astck);
	else if (!*astck && bstck && (*bstck)->next)
		swap_b(bstck);
}
