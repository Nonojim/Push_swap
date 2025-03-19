/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:16:54 by npederen          #+#    #+#             */
/*   Updated: 2025/03/17 21:31:29 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	how_many_bits(int n)
{
	int	i;

	i = 0;
	while (n >> i)
	{
		i++;
	}
	return (i);
}

int	ft_is_sort(t_stack *astack)
{
	int	i;

	if (astack->size <= 1)
		return (1);
	i = 0;
	while (i < astack->size - 1)
	{
		if (astack->value[i] > astack->value[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	radix_sort_base_2(t_stack *astack, t_stack *bstack)
{
	int	max;
	int	i;
	int	j;
	int	mask;
	int	size;

	i = 0;
	size = astack->size;
	max = how_many_bits(astack->size - 1);
	while (i < max)
	{
		j = 0;
		mask = 1 << i;
		while (j < size && (ft_is_sort(astack) == 0))
		{
			if ((astack->value[0] & mask) == 0)
				push_b(astack, bstack);
			else
				rotate_a(astack, bstack);
			j++;
		}
		while ((bstack->size) > 0)
			push_a(astack, bstack);
		i++;
	}
}
