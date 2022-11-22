/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:41:59 by luntiet-          #+#    #+#             */
/*   Updated: 2022/11/22 13:24:11 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_operate_calc(t_stacks *stck, int min, int pivot, int size)
{
	int	i;

	i = 0;
	while (stck->arr[i] != min && i < size)
		i++;
	if (stck->a && i > ft_stcksize(stck->a) / 2)
	{
		while (stck->a->index != min)
			ft_reverse_rotate_a(&stck->a);
		if (stck->a->index <= pivot)
			ft_push_b(&stck->a, &stck->b);
		else
		{
			ft_push_b(&stck->a, &stck->b);
			ft_rotate_b(&stck->b);
		}
	}
	else
	{
		while (stck->a && stck->a->index != min)
			ft_rotate_a(&stck->a);
		if (stck->a->index <= pivot)
		{
			ft_push_b(&stck->a, &stck->b);
		}
		else
		{
			ft_push_b(&stck->a, &stck->b);
			ft_rotate_b(&stck->b);
		}
	}
	ft_changearr(stck);
	return (1);
}

void	ft_sortback_to_a(t_stacks *stck)
{
	while (stck->b)
	{
		if (stck->b->index > ft_stcklast(stck->b)->index)
			ft_push_a(&stck->a, &stck->b);
		else
		{
			ft_reverse_rotate_b(&stck->b);
			ft_push_a(&stck->a, &stck->b);
		}
	}
}

void	ft_chunk_sort(t_stacks *stck, int chunk)
{
	int	chunksize;
	int	pivot;
	int	max;
	int	min;
	int	size;

	size = ft_stcksize(stck->a);
	chunksize = size / chunk;
	min = 0;
	max = chunksize - 1;
	pivot = max / 2;
	while (stck->a)
	{
		while (min <= max && min < size)
			min += ft_operate_calc(stck, min, pivot, size);
		max += chunksize;
		pivot = max - (chunksize / 2);
	}
	ft_sortback_to_a(stck);
}

void	ft_sort(t_stacks *stck)
{
	if (!(ft_stcksize(stck->a) <= 1))
	{
		if (ft_stcksize(stck->a) <= 3)
			ft_sort_three(&stck->a);
		else if (ft_stcksize(stck->a) <= 10)
			ft_counting_sort(stck);
		else
			ft_chunk(stck);
	}
}
