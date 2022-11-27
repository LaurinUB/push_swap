/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet <luntiet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:18:14 by luntiet-          #+#    #+#             */
/*   Updated: 2022/11/26 23:46:34 by luntiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_chunk(t_stacks *stck)
{
	if (ft_stcksize(stck->a) <= 25)
		ft_chunk_sort(stck, 1);
	else if (ft_stcksize(stck->a) <= 50)
		ft_chunk_sort(stck, 2);
	else if (ft_stcksize(stck->a) <= 100)
		ft_chunk_sort(stck, 4);
	else if (ft_stcksize(stck->a) <= 500)
		ft_chunk_sort(stck, 8);
	else if (ft_stcksize(stck->a) <= 1000)
		ft_chunk_sort(stck, 12);
	else
		ft_chunk_sort(stck, 18);
}

void	ft_sort_three(t_stack **a, int max)
{
	if (!ft_is_sorted((*a)))
	{
		if (ft_is_rev_sorted((*a)))
		{
			ft_rotate_a(&(*a));
			ft_swap_a(&(*a));
		}
		else if ((*a)->index == max - 2 && ft_stcklast((*a))->index == max - 1)
		{
			ft_reverse_rotate_a(&(*a));
			ft_swap_a(&(*a));
		}
		else if ((*a)->index == max && ft_stcklast((*a))->index == max - 1)
			ft_rotate_a(&(*a));
		else if ((*a)->index == max - 1)
		{
			if (ft_stcklast((*a))->index == max - 2)
				ft_reverse_rotate_a(&(*a));
			else
				ft_swap_a(&(*a));
		}
	}
}

void	ft_sort_five(t_stacks *stck)
{
	int	min;
	int	max;

	min = 0;
	max = ft_stcksize(stck->a) - 1;
	while (ft_stcksize(stck->a) > 3 && !ft_is_sorted(stck->a))
	{
		if (ft_first_occurence(stck->a, min) == 1)
			while (stck->a->index != min)
				ft_rotate_a(&stck->a);
		if (ft_first_occurence(stck->a, min) == 2)
			while (stck->a->index != min)
				ft_reverse_rotate_a(&stck->a);
		if (!ft_is_sorted(stck->a))
			ft_push_b(&stck->a, &stck->b);
		min++;
	}
	if (max == 4)
		ft_sort_three(&stck->a, 4);
	if (max == 3)
		ft_sort_three(&stck->a, 3);
	while (stck->b)
	{
		ft_push_a(&stck->a, &stck->b);
	}
}
