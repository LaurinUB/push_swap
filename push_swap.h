/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet <luntiet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:38:14 by luntiet-          #+#    #+#             */
/*   Updated: 2022/11/27 10:13:32 by luntiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}					t_stack;

typedef struct s_stacks
{
	struct s_stack	*a;
	struct s_stack	*b;
}					t_stacks;

//swapper
void		ft_swap_a(t_stack **stck);
void		ft_swap_b(t_stack **stck);
void		ft_swap(t_stack **astck, t_stack **bstck);
//pusher
void		ft_push_a(t_stack **astck, t_stack **bstck);
void		ft_push_b(t_stack **astck, t_stack **bstck);
//rotater
void		ft_rotate_a(t_stack **astck);
void		ft_rotate_b(t_stack **bstck);
void		ft_rotate(t_stack **astck, t_stack **bstck);
void		ft_reverse_rotate_a(t_stack **astck);
void		ft_reverse_rotate_b(t_stack **bstck);
void		ft_reverse_rotate(t_stack **astck, t_stack **bstck);
//stack
t_stacks	*ft_newstacks(t_stack *a);
t_stack		*ft_stcknew(int content);
int			ft_stcksize(t_stack *stck);
t_stack		*ft_stcklast(t_stack *stck);
void		ft_stckadd_back(t_stack **stck, t_stack *new);
void		ft_stckclear(t_stack *stck);
int			ft_stack_has_index(t_stack *stck, int nbr);
//indexing
void		ft_set_index(t_stack **stck);
int			ft_in_range(int index, int min, int max);
//sortcheck
int			ft_first_top(t_stacks *stck, int max);
int			ft_first_bot(t_stacks *stck, int max);
int			ft_is_rev_sorted(t_stack *stck);
int			ft_is_sorted(t_stack *stck);
void		ft_sort(t_stacks *stck);
void		ft_chunk(t_stacks *stck);
void		ft_chunk_sort(t_stacks *stck, int chunk);
void		ft_sort_three(t_stack **a, int max);
void		ft_sort_five(t_stacks *stck);
void		ft_counting_sort(t_stacks *stck);
int			ft_first_occurence(t_stack *stck, int max);
//libftvariants
long		ft_atol(char *str);
int			ft_range(char **str);
void		ft_splitfree(char **str);
#endif
