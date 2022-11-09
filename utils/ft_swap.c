/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:54:20 by luntiet-          #+#    #+#             */
/*   Updated: 2022/11/09 16:23:06 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap_a(t_list **stck)
{
	t_list	*first;
	t_list	*third;

	if (*stck && ft_getnode(*stck)->next)
	{
		first = *stck;
		*stck = first->next;
		third = ft_getnode(*stck)->next;
		first->next = third;
		ft_getnode(*stck)->next = first;
	}
}

void	ft_swap_b(t_list **stck)
{
	t_list	*first;
	t_list	*third;

	if (*stck && ft_getnode(*stck)->next)
	{
		first = *stck;
		*stck = first->next;
		third = ft_getnode(*stck)->next;
		first->next = third;
		ft_getnode(*stck)->next = first;
	}
}

void	ft_swap(t_list **astck, t_list **bstck)
{
	ft_swap_a(astck);
	ft_swap_b(bstck);
}
