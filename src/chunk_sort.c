/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:41:59 by luntiet-          #+#    #+#             */
/*   Updated: 2022/12/16 10:46:56 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	first_occurence(t_stack *stck, int max)
{
	int		pos;
	int		mid;
	int		size;
	t_stack	*tmp;

	pos = 0;
	size = stcksize(stck);
	mid = size / 2;
	tmp = stck;
	while (tmp->index != max)
	{
		tmp = tmp->next;
		pos++;
	}
	if (pos > mid)
		return (2);
	if (pos <= mid)
		return (1);
	return (0);
}

int	operate_calc(t_stacks *stck, int pivot, int max)
{
	while (stck->a->index != first_top(stck, max))
		rotate_a(&stck->a);
	if (stck->a->index > pivot)
	{
		push_b(&stck->a, &stck->b);
		rotate_b(&stck->b);
	}
	else
		push_b(&stck->a, &stck->b);
	return (1);
}

void	sortback_to_a(t_stacks *stck)
{
	int	max;

	max = stcksize(stck->b) - 1;
	while (max >= 0)
	{
		if (first_occurence(stck->b, max) == 1)
		{
			while (stck->b->index != max)
				rotate_b(&stck->b);
			push_a(&stck->a, &stck->b);
		}
		else if (first_occurence(stck->b, max) == 2)
		{
			while (stck->b->index != max)
				reverse_rotate_b(&stck->b);
			push_a(&stck->a, &stck->b);
		}
		max--;
	}
}

void	chunk_sort(t_stacks *stck, int chunk)
{
	int	chunksize;
	int	pivot;
	int	max;
	int	min;
	int	size;

	size = stcksize(stck->a);
	chunksize = size / chunk;
	min = 0;
	max = chunksize - 1;
	pivot = max / 2;
	while (stck->a)
	{
		while (min <= max && min < size)
			min += operate_calc(stck, pivot, max);
		max += chunksize;
		pivot = max - (chunksize / 2);
	}
	sortback_to_a(stck);
}

void	sort(t_stacks *stck)
{
	if (stcksize(stck->a) == 1)
		ft_putstr_fd("Error\n", 2);
	else
	{
		if (stcksize(stck->a) == 2)
		{
			if (stck->a->index > stck->a->next->index)
				swap_a(&stck->a);
		}
		else if (stcksize(stck->a) == 3)
			sort_three(&stck->a, 2);
		else if (stcksize(stck->a) <= 5)
			sort_five(stck);
		else
			chunk_size(stck);
	}
}
