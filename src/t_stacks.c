/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stacks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 08:37:37 by luntiet           #+#    #+#             */
/*   Updated: 2022/11/25 17:47:57 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stacks	*ft_newstacks(t_stack *a)
{
	t_stacks	*new;

	if (!a)
		return (NULL);
	new = malloc(sizeof(t_stacks));
	if (!new)
		return (NULL);
	new->a = a;
	new->b = NULL;
	return (new);
}
