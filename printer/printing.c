/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:59:41 by luntiet-          #+#    #+#             */
/*   Updated: 2022/11/11 14:00:37 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_printindex(t_stack *stck)
{
	while (stck)
	{
		ft_printf("%d\n", stck->index);
		stck = stck->next;
	}
}

void	ft_printstck(t_stack *stck)
{
	while (stck)
	{
		ft_printf("%d\n", stck->content);
		stck = stck->next;
	}
}

void	ft_printstcks(t_stack *a, t_stack *b)
{
	while (a || b)
	{
		if (!a)
			ft_printf("\t");
		else
		{
			ft_printf("  %d	", a->content);
			a = a->next;
		}
		if (!b)
			ft_printf("\n");
		else
		{
			ft_printf("  %d\n", b->content);
			b = b->next;
		}
	}
	ft_printf("< a >	< b >\n");
}

void	ft_teststacks(t_stack **astck, t_stack **bstck)
{
	ft_printstcks(*astck, *bstck);
	ft_printf("swap a:\n");
	ft_swap_a(astck);
	ft_printstcks(*astck, *bstck);
	ft_printf("push b 4x:\n");
	ft_push_b(astck, bstck);
	ft_push_b(astck, bstck);
	ft_push_b(astck, bstck);
	ft_push_b(astck, bstck);
	ft_printstcks(*astck, *bstck);
	ft_printf("push a:\n");
	ft_push_a(astck, bstck);
	ft_printstcks(*astck, *bstck);
	ft_printf("rotate\n");
	ft_rotate(astck, bstck);
	ft_printstcks(*astck, *bstck);
	ft_printf("reverse rotate\n");
	ft_reverse_rotate(astck, bstck);
	ft_printstcks(*astck, *bstck);
}
