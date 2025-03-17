/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_unused_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:19:05 by npederen          #+#    #+#             */
/*   Updated: 2025/03/17 12:22:45 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

int	swap_a(t_stack *astack, t_stack *bstack)
{
	(void)bstack;
	ft_swap(&astack->value[0], &astack->value[1]);
	return(0);	
}

int	swap_b(t_stack *astack, t_stack *bstack)
{
	(void)astack;
	ft_swap(&bstack->value[0], &bstack->value[1]);
	return(0);	
}

int	ss(t_stack *astack, t_stack *bstack)
{
	ft_swap(&astack->value[0], &astack->value[1]);
	ft_swap(&bstack->value[0], &bstack->value[1]);
	return(0);	
}

