/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 09:45:39 by luntiet-          #+#    #+#             */
/*   Updated: 2022/11/28 10:04:00 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rotate_a(t_stack **astck)
{
	t_stack	*tmp;

	if (astck && (*astck) && (*astck)->next)
	{
		tmp = *astck;
		*astck = tmp->next;
		tmp->next = NULL;
		ft_stckadd_back(astck, tmp);
		ft_printf("ra\n");
	}
}

void	ft_rotate_b(t_stack **bstck)
{
	t_stack	*tmp;

	if (bstck && (*bstck) && (*bstck)->next)
	{
		tmp = *bstck;
		*bstck = tmp->next;
		tmp->next = NULL;
		ft_stckadd_back(bstck, tmp);
		ft_printf("rb\n");
	}
}

void	ft_rotate(t_stack **astck, t_stack **bstck)
{
	t_stack	*tmp;

	if (astck && (*astck)->next && bstck && (*bstck)->next)
	{
		tmp = *astck;
		*astck = tmp->next;
		tmp->next = NULL;
		ft_stckadd_back(astck, tmp);
		tmp = *bstck;
		*bstck = tmp->next;
		tmp->next = NULL;
		ft_stckadd_back(bstck, tmp);
		ft_printf("rr\n");
	}
	else if (astck && (*astck)->next && !*bstck)
		ft_rotate_a(astck);
	else if (!*astck && bstck && (*bstck)->next)
		ft_rotate_b(bstck);
}
