/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:40:19 by luntiet-          #+#    #+#             */
/*   Updated: 2022/12/16 10:45:11 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate_a(t_stack **astck)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (astck && (*astck)->next)
	{
		tmp = stcklast(*astck);
		tmp2 = *astck;
		tmp->next = *astck;
		while (tmp2->next != tmp)
			tmp2 = tmp2->next;
		tmp2->next = NULL;
		*astck = tmp;
		ft_printf("rra\n");
	}
}

void	reverse_rotate_b(t_stack **bstck)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (bstck && (*bstck)->next)
	{
		tmp = stcklast(*bstck);
		tmp2 = *bstck;
		tmp->next = *bstck;
		while (tmp2->next != tmp)
			tmp2 = tmp2->next;
		tmp2->next = NULL;
		*bstck = tmp;
		ft_printf("rrb\n");
	}
}

void	reverse_rotate(t_stack **astck, t_stack **bstck)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (astck && (*astck)->next && bstck && (*bstck)->next)
	{
		tmp = stcklast(*astck);
		tmp2 = *astck;
		tmp->next = *astck;
		while (tmp2->next != tmp)
			tmp2 = tmp2->next;
		tmp2->next = NULL;
		*astck = tmp;
		tmp = stcklast(*bstck);
		tmp2 = *bstck;
		tmp->next = *bstck;
		while (tmp2->next != tmp)
			tmp2 = tmp2->next;
		tmp2->next = NULL;
		*bstck = tmp;
		ft_printf("rrr\n");
	}
	else if (astck && (*astck)->next && !*bstck)
		reverse_rotate_a(astck);
	else if (!*astck && bstck && (*bstck)->next)
		reverse_rotate_b(bstck);
}
