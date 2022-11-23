/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stacks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 08:37:37 by luntiet           #+#    #+#             */
/*   Updated: 2022/11/23 17:37:12 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stacks	*ft_newstacks(t_stack *a)
{
	t_stacks	*new;
	t_stack		*b;
	int			*arr;
	int			i;

	if (!a)
		return (NULL);
	b = NULL;
	i = 0;
	arr = malloc((ft_stcksize(a)) * sizeof(int));
	new = malloc(sizeof(t_stacks));
	if (!new || !arr)
		return (NULL);
	new->a = a;
	new->b = b;
	while (a)
	{
		arr[i] = a->index;
		a = a->next;
		i++;
	}
	new->arr = arr;
	return (new);
}
