/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:41:59 by luntiet-          #+#    #+#             */
/*   Updated: 2022/11/16 20:42:09 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push_sort_a(t_stack **astck, t_stack **bstck, int pivot, int chunk)
{
	while (*astck)
	{
		if ((*astck)->index >= pivot)
		{
			ft_push_b(astck, bstck);
			ft_rotate_b(bstck);
		}
		else if((*astck)->index < pivot)
			ft_push_b(astck, bstck);
	}
}

void	ft_push_sort_b(t_stack **astck, t_stack **bstck, int pivot, int chunk)
{
	while (*astck && chunk)
	{
		if ((*bstck)->index >= pivot)
		{
			ft_push_a(astck, bstck);
			ft_rotate_a(astck);
			chunk--;
		}
		else if((*bstck)->index < pivot)
		{
			ft_push_a(astck, bstck);
			chunk--;
		}
	}
}

void	ft_sort(t_stack **astck, t_stack **bstck)
{
	int		pivot;
	int		chunk;
	char	*str;

	str = malloc(ft_stcksize(*astck));
	chunk = 10;

	while (!ft_is_sorted(*astck))
	{
		ft_push_sort_a(astck, bstck, pivot, chunk);
		ft_push_sort_b(astck, bstck, pivot, chunk);
	}
}
