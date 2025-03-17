/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:12:24 by npederen          #+#    #+#             */
/*   Updated: 2025/03/17 21:27:40 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s != '\0')
	{
		write(fd, s, 1);
		s++;
	}
}

void	ft_swap(int *a, int*b)
{
	int	k;

	k = *a;
	*a = *b;
	*b = k;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			ft_swap(&tab[i], &tab[i + 1]);
			if (i == 0)
				i -= 1;
			else
				i -= 2;
		}
		i++;
	}
}

void	normalize_values(t_stack *astack, int *sorted, int *normalized)
{
	int	i;
	int	j;

	i = 0;
	while (i < astack->size)
	{
		j = 0;
		while (j < astack->size)
		{
			if (astack->value[i] == sorted[j])
			{
				normalized[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	normalize(t_stack	*astack)
{
	int		i;
	int		*sorted;
	int		*normalized;

	sorted = malloc(sizeof(int) * astack->size);
	normalized = malloc(sizeof(int) * astack->size);
	if (!sorted || !normalized)
		return ;
	i = 0;
	while (i < astack->size)
	{
		sorted[i] = astack->value[i];
		i++;
	}
	ft_sort_int_tab(sorted, astack->size);
	normalize_values(astack, sorted, normalized);
	i = 0;
	while (i < astack->size)
	{
		astack->value[i] = normalized[i];
		i++;
	}
	free(sorted);
	free(normalized);
}
