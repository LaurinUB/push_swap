/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:40:19 by luntiet-          #+#    #+#             */
/*   Updated: 2022/11/10 10:48:25 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_reverse_rotate_a(t_stack **astck)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (astck && ft_getnode(*astck)->next)
	{
		tmp = ft_stcklast(*astck);
		tmp2 = *astck;
		tmp->next = *astck;
		while (tmp2->next != tmp)
			tmp2 = tmp2->next;
		tmp2->next = NULL;
		*astck = tmp;
	}
}

void	ft_reverse_rotate_b(t_stack **bstck)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (bstck && ft_getnode(*bstck)->next)
	{
		tmp = ft_stcklast(*bstck);
		tmp2 = *bstck;
		tmp->next = *bstck;
		while (tmp2->next != tmp)
			tmp2 = tmp2->next;
		tmp2->next = NULL;
		*bstck = tmp;
	}
}

void	ft_reverse_rotate(t_stack **astck, t_stack **bstck)
{
	if (*astck && *bstck)
	{
		ft_reverse_rotate_a(astck);
		ft_reverse_rotate_b(bstck);
	}
	if (*astck && !*bstck)
		ft_reverse_rotate_a(astck);
	if (!*astck && *bstck)
		ft_reverse_rotate_b(bstck);
}
