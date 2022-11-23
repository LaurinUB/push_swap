/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:41:59 by luntiet-          #+#    #+#             */
/*   Updated: 2022/11/23 19:30:29 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_first_occurence(t_stacks *stck, int max)
{
	int	pos;
	int	mid;
	int	size;

	pos = 0;
	size = ft_stcksize(stck->a);
	mid = size / 2;
	while (!(stck->arr[pos] <= max) && stck->arr[pos] < size)
		pos++;
	if (pos >= mid)
		return (2);
	if (pos < mid)
		return (1);
	return (0);
}

int	ft_operate_calc(t_stacks *stck, int pivot, int max)
{
	if (ft_first_occurence(stck,  max) == 1)
	{
		while (stck->a->index != ft_first_top(stck, max))
			ft_rotate_a(&stck->a);
		if (stck->a->index > pivot)
		{
			ft_push_b(&stck->a, &stck->b);
			ft_rotate_b(&stck->b);
		}
		else
			ft_push_b(&stck->a, &stck->b);
	}
	else if (ft_first_occurence(stck, max) == 2)
	{
		while (stck->a->index != ft_first_bot(stck, max))
			ft_reverse_rotate_a(&stck->a);
		if (stck->a->index > pivot)
		{
			ft_push_b(&stck->a, &stck->b);
			ft_rotate_b(&stck->b);
		}
		else
			ft_push_b(&stck->a, &stck->b);
	}
	return (ft_changearr(stck), 1);
}

void	ft_sortback_to_a(t_stacks *stck)
{
	while (stck->b)
	{
		if (stck->b->index > ft_stcklast(stck->b)->index)
			ft_push_a(&stck->a, &stck->b);
		else
		{
			ft_push_a(&stck->a, &stck->b);
			ft_reverse_rotate_b(&stck->b);
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
			min += ft_operate_calc(stck, pivot, max);
		max += chunksize;
		pivot = max - (chunksize / 2);
	}
	//ft_sortback_to_a(stck);
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
