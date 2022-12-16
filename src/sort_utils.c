/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:18:14 by luntiet-          #+#    #+#             */
/*   Updated: 2022/12/16 10:50:16 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	chunk_size(t_stacks *stck)
{
	if (stcksize(stck->a) <= 25)
		chunk_sort(stck, 1);
	else if (stcksize(stck->a) <= 50)
		chunk_sort(stck, 2);
	else if (stcksize(stck->a) <= 100)
		chunk_sort(stck, 4);
	else if (stcksize(stck->a) <= 500)
		chunk_sort(stck, 8);
	else if (stcksize(stck->a) <= 1000)
		chunk_sort(stck, 12);
	else
		chunk_sort(stck, 18);
}

int	first_top(t_stacks *stck, int max)
{
	t_stack	*tmp;

	tmp = stck->a;
	while (!(tmp->index <= max))
	{
		tmp = tmp->next;
	}
	return (tmp->index);
}
