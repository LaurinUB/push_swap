/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:32:17 by luntiet-          #+#    #+#             */
/*   Updated: 2022/11/11 13:56:00 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push_a(t_stack **astck, t_stack **bstck)
{
	t_stack	*tmp;

	if (!*astck)
	{
		tmp = *bstck;
		*bstck = tmp->next;
		tmp->next = NULL;
		*astck = tmp;
	}
	if (*bstck && astck)
	{
		tmp = *bstck;
		*bstck = tmp->next;
		tmp->next = ft_getnode(*astck);
		*astck = tmp;
	}
}

void	ft_push_b(t_stack **astck, t_stack **bstck)
{
	t_stack	*tmp;

	if (!*bstck)
	{
		tmp = *astck;
		*astck = tmp->next;
		tmp->next = NULL;
		*bstck = tmp;
	}
	else if (bstck && *astck)
	{
		tmp = *astck;
		*astck = tmp->next;
		tmp->next = ft_getnode(*bstck);
		*bstck = tmp;
	}
}
