/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stacks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 08:37:37 by luntiet           #+#    #+#             */
/*   Updated: 2022/11/22 10:29:22 by luntiet-         ###   ########.fr       */
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
	arr = malloc((ft_stcksize(a) + 1) * sizeof(int));
	new = malloc(sizeof(t_stacks));
	new->a = a;
	new->b = b;
	while (a)
	{
		arr[i++] = a->index;
		a = a->next;
	}
	arr[i] = '\0';
	new->arr = arr;
	return (free(arr), new);
}
