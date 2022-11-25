/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:36:48 by luntiet-          #+#    #+#             */
/*   Updated: 2022/11/25 14:40:50 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_stcknew(int content)
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

int	ft_stcksize(t_stack *stck)
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

t_stack	*ft_stcklast(t_stack *stck)
{
	if (!stck)
		return (stck);
	while (stck->next)
	{
		stck = stck->next;
	}
	return (stck);
}

void	ft_stckadd_back(t_stack **stck, t_stack *new)
{
	if (*stck == NULL)
	{
		*stck = new;
		new->next = NULL;
	}
	if (ft_stcksize(new) > 1)
	{
		ft_stcklast(*stck)->next = new;
		ft_stcklast(*stck)->next = NULL;
	}
	else
	{
		ft_stcklast(*stck)->next = new;
		new->next = NULL;
	}
}

void	ft_stckclear(t_stack **stck)
{
	t_stack	*tmp;
	t_stack	*dl;

	if (!*stck)
		stck = NULL;
	if (stck && *stck)
	{
		tmp = *stck;
		dl = tmp;
		while (tmp)
		{
			tmp = tmp->next;
			free(dl);
			dl = tmp;
		}
		free(stck);
	}
}
