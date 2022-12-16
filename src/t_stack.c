/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:36:48 by luntiet-          #+#    #+#             */
/*   Updated: 2022/12/16 13:27:06 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*stck_new(int content)
{
	t_stack	*element;

	element = malloc(sizeof(t_stack));
	if (!element)
		return (NULL);
	element->content = content;
	element->index = -1;
	element->next = NULL;
	return (element);
}

int	stcksize(t_stack *stck)
{
	int		count;
	t_stack	*tmp;

	count = 0;
	if (!stck)
		return (count);
	tmp = stck;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}

t_stack	*stcklast(t_stack *stck)
{
	if (!stck)
		return (stck);
	while (stck->next)
	{
		stck = stck->next;
	}
	return (stck);
}

void	stckadd_back(t_stack **stck, t_stack *new)
{
	if (*stck == NULL)
	{
		*stck = new;
		new->next = NULL;
	}
	if (stcksize(new) > 1)
	{
		stcklast(*stck)->next = new;
		stcklast(*stck)->next = NULL;
	}
	else
	{
		stcklast(*stck)->next = new;
		new->next = NULL;
	}
}

void	stckclear(t_stack *stck)
{
	t_stack	*tmp;
	t_stack	*dl;

	if (!stck)
		stck = NULL;
	if (stck)
	{
		tmp = stck;
		while (tmp)
		{
			dl = tmp;
			tmp = tmp->next;
			free(dl);
		}
		stck = NULL;
	}
}
