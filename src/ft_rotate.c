/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 09:45:39 by luntiet-          #+#    #+#             */
/*   Updated: 2022/12/16 10:46:03 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_a(t_stack **astck)
{
	t_stack	*tmp;

	if (astck && (*astck) && (*astck)->next)
	{
		tmp = *astck;
		*astck = tmp->next;
		tmp->next = NULL;
		stckadd_back(astck, tmp);
		ft_printf("ra\n");
	}
}

void	rotate_b(t_stack **bstck)
{
	t_stack	*tmp;

	if (bstck && (*bstck) && (*bstck)->next)
	{
		tmp = *bstck;
		*bstck = tmp->next;
		tmp->next = NULL;
		stckadd_back(bstck, tmp);
		ft_printf("rb\n");
	}
}

void	rotate(t_stack **astck, t_stack **bstck)
{
	t_stack	*tmp;

	if (astck && (*astck)->next && bstck && (*bstck)->next)
	{
		tmp = *astck;
		*astck = tmp->next;
		tmp->next = NULL;
		stckadd_back(astck, tmp);
		tmp = *bstck;
		*bstck = tmp->next;
		tmp->next = NULL;
		stckadd_back(bstck, tmp);
		ft_printf("rr\n");
	}
	else if (astck && (*astck)->next && !*bstck)
		rotate_a(astck);
	else if (!*astck && bstck && (*bstck)->next)
		rotate_b(bstck);
}
