/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:38:14 by luntiet-          #+#    #+#             */
/*   Updated: 2022/11/09 16:06:27 by luntiet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include "./libft/libft.h"

//swapper
void	ft_swap_a(t_list **stck);
void	ft_swap_b(t_list **stck);
void	ft_swap(t_list **astck, t_list **bstck);
//pusher
void	ft_push_a(t_list **astck, t_list **bstck);
void	ft_push_b(t_list **astck, t_list **bstck);
//rotater
void	ft_rotate_a(t_list **astck);
void	ft_rotate_b(t_list **bstck);
void	ft_rotate(t_list **astck, t_list **bstck);
void	ft_reverse_rotate_a(t_list **astck);
void	ft_reverse_rotate_b(t_list **bstck);
void	ft_reverse_rotate(t_list **astck, t_list **bstck);
//getter
t_list	*ft_getnode(t_list *stck);
void	*ft_getstckcontent(t_list *stck);

#endif
