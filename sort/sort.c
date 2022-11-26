/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:41:59 by luntiet-          #+#    #+#             */
/*   Updated: 2022/11/26 15:06:58 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_first_occurence(t_stack *stck, int max)
{
	int		pos;
	int		mid;
	int		size;
	t_stack	*tmp;

	pos = 0;
	size = ft_stcksize(stck);
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

int	ft_operate_calc(t_stacks *stck, int pivot, int max)
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
	return (1);
}

void	ft_sortback_to_a(t_stacks *stck)
{
	int	max;

	max = ft_stcksize(stck->b) - 1;
	while (max >= 0)
	{
		if (ft_first_occurence(stck->b, max) == 1)
		{
			while (stck->b->index != max)
				ft_rotate_b(&stck->b);
			ft_push_a(&stck->a, &stck->b);
		}
		else if (ft_first_occurence(stck->b, max) == 2)
		{
			while (stck->b->index != max)
				ft_reverse_rotate_b(&stck->b);
			ft_push_a(&stck->a, &stck->b);
		}
		max--;
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
	ft_sortback_to_a(stck);
}

void	ft_sort(t_stacks *stck)
{
	if (ft_stcksize(stck->a) <= 1)
	{
		ft_putstr_fd("Error\n", 2);
	}
	else
	{
		if (ft_stcksize(stck->a) == 2)
		{
			if (stck->a->index > stck->a->next->index)
				ft_swap_a(&stck->a);
		}
		else if (ft_stcksize(stck->a) == 3)
			ft_sort_three(&stck->a, 2);
		else if (ft_stcksize(stck->a) <= 5)
			ft_sort_five(stck);
		else
			ft_chunk(stck);
	}

}
