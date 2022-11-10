/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:07:36 by luntiet-          #+#    #+#             */
/*   Updated: 2022/11/10 18:41:20 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printstck(t_stack *a, t_stack *b)
{
	while (a || b)
	{
		if(!a)
			ft_printf("\t");
		else
		{
			ft_printf("  %d	", a->content);
			a = a->next;
		}
		if (!b)
			ft_printf("\n");
		else
		{
			ft_printf("  %d\n", b->content);
			b = b->next;
		}
	}
	ft_printf("< a >	< b >\n");
}

void	ft_printstacks(t_stack **astck, t_stack **bstck)
{
	ft_printstck(*astck, *bstck);
	ft_printf("swap a:\n");
	ft_swap_a(astck);
	ft_printstck(*astck, *bstck);
	ft_printf("push b 4x:\n");
	ft_push_b(astck, bstck);
	ft_push_b(astck, bstck);
	ft_push_b(astck, bstck);
	ft_push_b(astck, bstck);
	ft_printstck(*astck, *bstck);
	ft_printf("push a:\n");
	ft_push_a(astck, bstck);
	ft_printstck(*astck, *bstck);
	ft_printf("rotate\n");
	ft_rotate(astck, bstck);
	ft_printstck(*astck, *bstck);
	ft_printf("reverse rotate\n");
	ft_reverse_rotate(astck, bstck);
	ft_printstck(*astck, *bstck);
}

int	main(int argc, char **argv)
{
	t_stack	**astck;
	t_stack	**bstck;
	int		i;
	t_stack	*tmp;

	i = 1;
	astck = (t_stack **)malloc(sizeof(t_stack **));
	if (!astck)
		return (0);
	bstck = (t_stack **)malloc(sizeof(t_stack **));
	if (!bstck)
		return (0);
	if (argc < 1)
		ft_printf("Error");
	i = 1;
	if (argc > 1 /*&& ft_is_int(argv)*/)
	{
		while (i < argc)
		{
			tmp = ft_stcknew(ft_atoi(argv[i]));
			ft_stckadd_back(astck, tmp);
			i++;
		}
		//ft_printstacks(astck,bstck);
	}
	return (0);
}
