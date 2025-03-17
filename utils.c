/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:12:24 by npederen          #+#    #+#             */
/*   Updated: 2025/03/17 12:24:24 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	if ((size_t)dest >= (size_t)src)
	{
		while (n > 0)
		{
			(((char *)dest)[n - 1] = ((char *)src)[n - 1]);
			n--;
		}
	}
	else
	{
		while (i < n)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dest);
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

void	normalize(t_stack	*astack)
{
	int		i;
	int		j;
	int	*sorted;
	int	*normalized;

	sorted = malloc(sizeof(int) * astack->size);
	normalized = malloc(sizeof(int) * astack->size);
	if (!sorted || !normalized)
	return;
	i = 0;
	while (i < astack->size) {
		sorted[i] = astack->value[i];
		i++;
	}
	ft_sort_int_tab(sorted, astack->size);
	i = 0;
	while (i < astack->size) {
	j = 0;
		while (j < astack->size) {
			if (astack->value[i] == sorted[j]) {
				normalized[i] = j;
				break;
			}
			j++;
		}
		i++;
	}

	i = 0;
	while (i < astack->size) {
		astack->value[i] = normalized[i];
		i++;
	}
	free(sorted);
	free(normalized);
}

