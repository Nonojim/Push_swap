/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:44:31 by npederen          #+#    #+#             */
/*   Updated: 2025/03/18 19:03:07 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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
int		how_many_bits(int n);
int		ft_is_sort(t_stack *astack);
void	radix_sort_base_2(t_stack *astack, t_stack *bstack);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	ft_swap(int *a, int*b);
void	ft_sort_int_tab(int *tab, int size);
void	normalize(t_stack	*astack);
void	sort_3(t_stack *astack, t_stack *bstack);
void	sort_4_5(t_stack *astack, t_stack *bstack);
void	ft_putstr_fd(char *s, int fd);
void	free_stacks(t_stack *astack, t_stack *bstack, char option);
void	check_doubles(t_stack *astack, t_stack *bstack);
long	ft_atoi(char *nptr, t_stack *astack, t_stack *bstack);
void	normalize_values(t_stack *astack, int *sorted, int *normalized);

#endif
