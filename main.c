/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:07:36 by luntiet-          #+#    #+#             */
/*   Updated: 2022/11/08 11:26:17 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstcontent(t_list	*elmnt)
{
	return (elmnt->content);
}

int	main(void)
{
	t_list	**astck;
	t_list	**bstck;

	astck = (t_list **)malloc(sizeof(t_list **));
	if (!astck)
		return (NULL);
	bstck = (t_list **)malloc(sizeof(t_list **));
	if (!bstck)
		return (NULL);
	*astck = ft_lstnew("A");
	ft_lstadd_back(astck, ft_lstnew("B"));
	ft_printf("%s, %s\n", ft_lstcontent(*astck), ft_lstlast(*astck)->content);
	ft_lstadd_back(astck, ft_lstnew("C"));
	ft_printf("%s\n", ft_lstlast(*astck)->content);
	return (0);
}
