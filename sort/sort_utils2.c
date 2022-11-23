/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:11:59 by luntiet-          #+#    #+#             */
/*   Updated: 2022/11/23 19:26:55 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_first_top(t_stacks *stck, int max)
{
	int	i;
	int	size;

	i = 0;
	size = ft_stcksize(stck->a);
	while (!(stck->arr[i] <= max) && i < size)
		i++;
	return (stck->arr[i]);
}

int	ft_first_bot(t_stacks *stck, int max)
{
	int	i;

	i = ft_stcksize(stck->a) - 1;
	while (!(stck->arr[i] <= max) && i < 0)
		i--;
	return (stck->arr[i]);
}

int	ft_in_range(int index, int min, int max)
{
	return (index >= min && index <= max);
}
