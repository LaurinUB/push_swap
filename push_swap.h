/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:38:14 by luntiet-          #+#    #+#             */
/*   Updated: 2022/12/16 11:29:17 by luntiet-         ###   ########.fr       */
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
void		swap_a(t_stack **stck);
void		swap_b(t_stack **stck);
void		swap(t_stack **astck, t_stack **bstck);
//pusher
void		push_a(t_stack **astck, t_stack **bstck);
void		push_b(t_stack **astck, t_stack **bstck);
//rotater
void		rotate_a(t_stack **astck);
void		rotate_b(t_stack **bstck);
void		rotate(t_stack **astck, t_stack **bstck);
void		reverse_rotate_a(t_stack **astck);
void		reverse_rotate_b(t_stack **bstck);
void		reverse_rotate(t_stack **astck, t_stack **bstck);
//stack
t_stacks	*new_stacks(t_stack *a);
t_stack		*stck_new(int content);
int			stcksize(t_stack *stck);
t_stack		*stcklast(t_stack *stck);
void		stckadd_back(t_stack **stck, t_stack *new);
void		stckclear(t_stack *stck);
//indexing
void		set_index(t_stack **stck);
//sort
void		sort_five(t_stacks *stck);
void		sort_three(t_stack **a, int max);
void		sort(t_stacks *stck);
void		chunk_sort(t_stacks *st, int chunksize);
//sort utils
int			first_top(t_stacks *stck, int max);
int			first_bot(t_stacks *stck, int max);
int			is_rev_sorted(t_stack *stck);
int			is_sorted(t_stack *stck);
void		chunk_size(t_stacks *stck);
int			first_occurence(t_stack *stck, int max);
//utils
void		splitnstck_free(t_stack *a, char **split);
void		stackfree(t_stacks *stck);
int			is_int(char **str);
void		splitfree(char **str);
int			check_input(char *arv);
#endif
