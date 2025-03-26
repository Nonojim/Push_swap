/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:52:09 by npederen          #+#    #+#             */
/*   Updated: 2025/03/19 01:03:23 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stacks(t_stack *astack, t_stack *bstack, char option)
{
	free(astack->value);
	free(bstack->value);
	if (option == 'i')
		exit(1);
	if (option == 'e')
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
}

void	check_doubles(t_stack *astack, t_stack *bstack)
{
	int	i;
	int	j;

	i = 0;
	while (i < (astack->size - 1))
	{
		j = i + 1;
		while (j < astack->size)
		{
			if (astack->value[i] == astack->value[j])
				free_stacks(astack, bstack, 'e');
			j++;
		}
		i++;
	}
}

long	ft_atoi(char *nptr, t_stack *astack, t_stack *bstack)
{
	long		i;
	long		sign;
	long		result;

	i = 0;
	sign = 1;
	result = 0;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	if (result * sign < -2147483648 || result * sign > 2147483647 || nptr[i])
		free_stacks(astack, bstack, 'e');
	return (result * sign);
}
