/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 10:24:44 by luntiet-          #+#    #+#             */
/*   Updated: 2022/12/16 10:47:27 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_five(t_stacks *stck)
{
	int	min;
	int	max;

	min = 0;
	max = stcksize(stck->a) - 1;
	while (stcksize(stck->a) > 3 && !is_sorted(stck->a))
	{
		if (first_occurence(stck->a, min) == 1)
			while (stck->a->index != min)
				rotate_a(&stck->a);
		if (first_occurence(stck->a, min) == 2)
			while (stck->a->index != min)
				reverse_rotate_a(&stck->a);
		if (!is_sorted(stck->a))
			push_b(&stck->a, &stck->b);
		min++;
	}
	if (max == 4)
		sort_three(&stck->a, 4);
	if (max == 3)
		sort_three(&stck->a, 3);
	while (stck->b)
	{
		push_a(&stck->a, &stck->b);
	}
}
