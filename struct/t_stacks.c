/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stacks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 08:37:37 by luntiet           #+#    #+#             */
/*   Updated: 2022/11/25 14:40:30 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stacks	*ft_newstacks(t_stack *a)
{
	t_stacks	*new;
	int			*arr;
	int			i;

	if (!a)
		return (NULL);
	i = 0;
	arr = malloc((ft_stcksize(a)) * sizeof(int));
	if (!arr)
		return (NULL);
	new = malloc(sizeof(t_stacks));
	if (!new)
		return (NULL);
	new->a = a;
	new->b = NULL;
	while (a)
	{
		arr[i] = a->index;
		a = a->next;
		i++;
	}
	new->arr = arr;
	return (new);
}
