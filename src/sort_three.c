/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 10:24:16 by luntiet-          #+#    #+#             */
/*   Updated: 2022/12/16 10:47:46 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_stack **a, int max)
{
	if (!is_sorted((*a)))
	{
		if (is_rev_sorted((*a)))
		{
			rotate_a(&(*a));
			swap_a(&(*a));
		}
		else if ((*a)->index == max - 2 && stcklast((*a))->index == max - 1)
		{
			reverse_rotate_a(&(*a));
			swap_a(&(*a));
		}
		else if ((*a)->index == max && stcklast((*a))->index == max - 1)
			rotate_a(&(*a));
		else if ((*a)->index == max - 1)
		{
			if (stcklast((*a))->index == max - 2)
				reverse_rotate_a(&(*a));
			else
				swap_a(&(*a));
		}
	}
}
