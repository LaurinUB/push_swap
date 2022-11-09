/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:07:36 by luntiet-          #+#    #+#             */
/*   Updated: 2022/11/09 16:03:03 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printlst(t_list *a, t_list *b)
{
	while (a || b)
	{
		if(!a)
			ft_printf("\t");
		else
		{
			ft_printf("  %d	", ft_atoi(a->content));
			a = a->next;
		}
		if (!b)
			ft_printf("\n");
		else
		{
			ft_printf("  %d\n", ft_atoi(b->content));
			b = b->next;
		}
	}
	ft_printf("< a >	< b >\n");
}

void	ft_printstacks(t_list **astck, t_list **bstck)
{
	ft_printlst(*astck, *bstck);
	ft_printf("swap a:\n");
	ft_swap_a(astck);
	ft_printlst(*astck, *bstck);
	ft_printf("push b 4x:\n");
	ft_push_b(astck, bstck);
	ft_push_b(astck, bstck);
	ft_push_b(astck, bstck);
	ft_push_b(astck, bstck);
	ft_printlst(*astck, *bstck);
	ft_printf("push a:\n");
	ft_push_a(astck, bstck);
	ft_printlst(*astck, *bstck);
	ft_printf("rotate\n");
	ft_rotate(astck, bstck);
	ft_printlst(*astck, *bstck);
	ft_printf("reverse rotate\n");
	ft_reverse_rotate(astck, bstck);
	ft_printlst(*astck, *bstck);
}

int	main(int argc, char **argv)
{
	t_list	**astck;
	t_list	**bstck;
	int		i;

	i = 1;
	astck = (t_list **)malloc(sizeof(t_list **));
	if (!astck)
		return (0);
	bstck = (t_list **)malloc(sizeof(t_list **));
	if (!bstck)
		return (0);
	if (argc < 1)
		ft_printf("Error");
	if (argc > 1)
	{
		*astck = ft_lstnew(argv[1]);
		i += 1;
		while (i < argc)
		{
			ft_lstadd_back(astck, ft_lstnew(argv[i]));
			i++;
		}
		ft_printstacks(astck,bstck);
	}
	return (0);
}
