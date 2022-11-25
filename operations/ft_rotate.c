/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:40:11 by luntiet-          #+#    #+#             */
/*   Updated: 2022/11/25 16:26:13 by luntiet-         ###   ########.fr       */
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

	if (*astck && *bstck)
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
}
