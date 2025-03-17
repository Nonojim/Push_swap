/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:44:31 by npederen          #+#    #+#             */
/*   Updated: 2025/03/17 16:30:46 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_h
#define PUSH_SWAP_h

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_stack
{
	int	*value;
	int	size;
}	t_stack;

int		push_a(t_stack *astack, t_stack *bstack);
int		push_b(t_stack *astack, t_stack *bstack);
int		rotate_a(t_stack *astack, t_stack *bstack);
int		rotate_b(t_stack *astack, t_stack *bstack);
int		rr(t_stack *astack, t_stack *bstack);
int		reverse_rotate_a(t_stack *astack, t_stack *bstack);
int		reverse_rotate_b(t_stack *astack, t_stack *bstack);
int		rrr(t_stack *astack, t_stack *bstack);
int		swap_a(t_stack *astack, t_stack *bstack);
int		swap_b(t_stack *astack, t_stack *bstack);
int		ss(t_stack *astack, t_stack *bstack);
int		how_many_bits(int	n);
int		ft_is_sort(int *tab, int length);
void	radix_sort_base_2(t_stack *astack, t_stack *bstack);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	ft_swap(int *a, int*b);
void	ft_sort_int_tab(int *tab, int size);
void	normalize(t_stack	*astack);
void	ft_putstr_fd(char *s, int fd);

#endif
