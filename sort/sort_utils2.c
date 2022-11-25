/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:11:59 by luntiet-          #+#    #+#             */
/*   Updated: 2022/11/25 14:40:10 by luntiet-         ###   ########.fr       */
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

void	ft_free(t_stacks *stck)
{
	ft_stckclear(&stck->a);
	//ft_stckclear(&stck->b);
	free(stck->arr);
	free(stck);
}
