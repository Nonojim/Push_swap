/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:37:13 by npederen          #+#    #+#             */
/*   Updated: 2025/03/17 12:21:25 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

int	push_a(t_stack *astack, t_stack *bstack)
{
	ft_memmove(&astack->value[1], &astack->value[0], astack->size * sizeof(int));
	astack->value[0] = bstack->value[0];
	ft_memmove(&bstack->value[0], &bstack->value[1], (bstack->size - 1) * sizeof(int));
	astack->size +=1;
	bstack->size -=1;
	printf("pa\n");
	return(0);	
}

int	push_b(t_stack *astack, t_stack *bstack)
{
	ft_memmove(&bstack->value[1], &bstack->value[0], bstack->size * sizeof(int));
	bstack->value[0] = astack->value[0];
	ft_memmove(&astack->value[0], &astack->value[1], (astack->size - 1) * sizeof(int));
	astack->size -=1;
	bstack->size +=1;
	printf("pb\n");
	return(0);	
}

int	rotate_a(t_stack *astack, t_stack *bstack)
{
	int tmp;
	
	(void)bstack;
	tmp = astack->value[0];
	ft_memmove(&astack->value[0], &astack->value[1], (astack->size - 1) * sizeof(int));
	astack->value[astack->size - 1] = tmp;
	printf("ra\n");
	return (0);
}

int	rotate_b(t_stack *astack, t_stack *bstack)
{
	int tmp;
	
	(void)astack;
	tmp = bstack->value[0];
	ft_memmove(&bstack->value[0], &bstack->value[1], (bstack->size - 1) * sizeof(int));
	bstack->value[bstack->size - 1] = tmp;
	return (0);
}
