/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:18:14 by luntiet-          #+#    #+#             */
/*   Updated: 2022/11/22 13:23:21 by luntiet-         ###   ########.fr       */
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
		ft_chunk_sort(stck, 20);
	else
		ft_chunk_sort(stck, 30);
}

void	ft_changearr(t_stacks *stck)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = stck->a;
	while (tmp)
	{
		stck->arr[i++] = tmp->index;
		tmp = tmp->next;
	}
}

void	ft_sort_three(t_stack **a)
{
	if (!ft_is_sorted(*a))
	{
		if (ft_is_rev_sorted(*a))
		{
			ft_rotate_a(a);
			ft_swap_a(a);
		}
		else if ((*a)->index == 0 && ft_stcklast(*a)->index == 1)
		{
			ft_reverse_rotate_a(a);
			ft_swap_a(a);
		}
		else if ((*a)->index == 2 && ft_stcklast(*a)->index == 1)
			ft_rotate_a(a);
		else if ((*a)->index == 1)
		{
			if (ft_stcklast(*a)->index == 0)
				ft_reverse_rotate_a(a);
			else
				ft_swap_a(a);
		}
	}
}

void	ft_counting_sort(t_stacks *stck)
{
	int	nbr;

	nbr = 0;
	while (nbr < 10 && stck->a)
	{
		while (!(stck->a->index == nbr))
			ft_rotate_a(&stck->a);
		ft_push_b(&stck->a, &stck->b);
		nbr++;
	}
	while (stck->b)
		ft_push_a(&stck->a, &stck->b);
}
