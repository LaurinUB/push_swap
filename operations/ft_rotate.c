/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:40:11 by luntiet-          #+#    #+#             */
/*   Updated: 2022/11/10 10:48:38 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rotate_a(t_stack **astck)
{
	t_stack	*tmp;

	if (astck && ft_getnode(*astck)->next)
	{
		tmp = *astck;
		*astck = tmp->next;
		tmp->next = NULL;
		ft_stckadd_back(astck, tmp);
	}
}

void	ft_rotate_b(t_stack **bstck)
{
	t_stack	*tmp;

	if (bstck && ft_getnode(*bstck)->next)
	{
		tmp = *bstck;
		*bstck = tmp->next;
		tmp->next = NULL;
		ft_stckadd_back(bstck, tmp);
	}
}

void	ft_rotate(t_stack **astck, t_stack **bstck)
{
	if (*astck && *bstck)
	{
		ft_rotate_a(astck);
		ft_rotate_a(bstck);
	}
	else if (*astck && !*bstck)
		ft_rotate_a(astck);
	else if (!*astck && *bstck)
		ft_rotate_a(bstck);
}
