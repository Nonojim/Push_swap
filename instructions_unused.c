/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_unused.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:13:57 by npederen          #+#    #+#             */
/*   Updated: 2025/03/17 12:21:59 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

int	rr(t_stack *astack, t_stack *bstack)
{
	int tmp;
	
	tmp = astack->value[0];
	ft_memmove(&astack->value[0], &astack->value[1], (astack->size - 1) * sizeof(int));
	astack->value[astack->size - 1] = tmp;
	tmp = bstack->value[0];
	ft_memmove(&bstack->value[0], &bstack->value[1], (bstack->size - 1) * sizeof(int));
	bstack->value[bstack->size - 1] = tmp;
	return (0);
}

int	reverse_rotate_a(t_stack *astack, t_stack *bstack)
{
	int tmp;
	
	(void)bstack;
	tmp = astack->value[astack->size - 1];
	ft_memmove(&astack->value[1], &astack->value[0], (astack->size - 1) * sizeof(int));
	astack->value[0] = tmp;
	return (0);
}

int	reverse_rotate_b(t_stack *astack, t_stack *bstack)
{
	int tmp;
	
	(void)astack;
	tmp = bstack->value[bstack->size - 1];
	ft_memmove(&bstack->value[1], &bstack->value[0], (bstack->size - 1) * sizeof(int));
	bstack->value[0] = tmp;
	return (0);
}

int	rrr(t_stack *astack, t_stack *bstack)
{
	int tmp;
	
	tmp = astack->value[astack->size - 1];
	ft_memmove(&astack->value[1], &astack->value[0], (astack->size - 1) * sizeof(int));
	astack->value[0] = tmp;
	tmp = bstack->value[bstack->size - 1];
	ft_memmove(&bstack->value[1], &bstack->value[0], (bstack->size - 1) * sizeof(int));
	bstack->value[0] = tmp;
	return (0);
}



