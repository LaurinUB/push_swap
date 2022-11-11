/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet <luntiet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:38:14 by luntiet-          #+#    #+#             */
/*   Updated: 2022/11/11 21:36:22 by luntiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
# include "limits.h"

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}					t_stack;

//swapper
void	ft_swap_a(t_stack **stck);
void	ft_swap_b(t_stack **stck);
void	ft_swap(t_stack **astck, t_stack **bstck);
//pusher
void	ft_push_a(t_stack **astck, t_stack **bstck);
void	ft_push_b(t_stack **astck, t_stack **bstck);
//rotater
void	ft_rotate_a(t_stack **astck);
void	ft_rotate_b(t_stack **bstck);
void	ft_rotate(t_stack **astck, t_stack **bstck);
void	ft_reverse_rotate_a(t_stack **astck);
void	ft_reverse_rotate_b(t_stack **bstck);
void	ft_reverse_rotate(t_stack **astck, t_stack **bstck);
//getter
t_stack	*ft_getnode(t_stack *stck);
int		ft_getstckcontent(t_stack *stck);
//stack
t_stack	*ft_stcknew(int content);
int		ft_stcksize(t_stack *stck);
t_stack	*ft_stcklast(t_stack *stck);
void	ft_stckadd_back(t_stack **stck, t_stack *new);
void	ft_stckclear(t_stack **stck, void (*del)(void *));
//indexing
void	ft_set_index(t_stack **stck);
int		ft_is_sorted(t_stack *astck);
//printing
void	ft_teststacks(t_stack **astck, t_stack **bstck);
void	ft_printstcks(t_stack *a, t_stack *b);
void	ft_printstck(t_stack *stck);
void	ft_printindex(t_stack *stck);

#endif
