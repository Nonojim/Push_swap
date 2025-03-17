/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:46:14 by npederen          #+#    #+#             */
/*   Updated: 2025/03/17 19:09:35 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *astack, t_stack *bstack)
{
	if (astack->value[2] != 2)
	{
		if (astack->value[0] == 2)
			rotate_a(astack, bstack);
		else
			reverse_rotate_a(astack, bstack);
	}
	if (astack->value[0] > astack->value[1])
		swap_a(astack, bstack);
}

void	sort_4_5(t_stack *astack, t_stack *bstack)
{
	while (bstack->size <= 1)
	{
		if (astack->value[0] == 0 || astack->value[0] == 1)
			push_b(astack, bstack);
		else
			rotate_a(astack, bstack);
	}
	if (bstack->value[0] == 0)
		swap_b(astack, bstack);
	if (astack->value[2] != 4)
	{
		if (astack->value[0] == 4)
			rotate_a(astack, bstack);
		else
			reverse_rotate_a(astack, bstack);
	}
	if (astack->value[0] > astack->value[1])
		swap_a(astack, bstack);
	push_a(astack, bstack);
	push_a(astack, bstack);
}
