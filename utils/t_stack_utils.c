/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack_getter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:53:38 by luntiet-          #+#    #+#             */
/*   Updated: 2022/11/11 13:57:03 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_getnode(t_stack *stck)
{
	if (!stck)
		return (NULL);
	return (stck);
}

int	ft_getstckcontent(t_stack *stck)
{
	if (!stck)
		return (0);
	return (stck->content);
}
