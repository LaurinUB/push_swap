/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:38:40 by luntiet-          #+#    #+#             */
/*   Updated: 2022/12/16 13:53:25 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	splitfree(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	stackfree(t_stacks *stck)
{
	stckclear(stck->a);
	free(stck);
}

void	splitnstck_free(t_stack *a, char **split)
{
	splitfree(split);
	stckclear(a);
}
