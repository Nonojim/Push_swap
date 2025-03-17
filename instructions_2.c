/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:19:05 by npederen          #+#    #+#             */
/*   Updated: 2025/03/17 21:19:16 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_a(t_stack *astack, t_stack *bstack)
{
	(void)bstack;
	ft_swap(&astack->value[0], &astack->value[1]);
	ft_putstr_fd("sa\n", 1);
	return (0);
}

int	swap_b(t_stack *astack, t_stack *bstack)
{
	(void)astack;
	ft_swap(&bstack->value[0], &bstack->value[1]);
	ft_putstr_fd("sb\n", 1);
	return (0);
}

int	ss(t_stack *astack, t_stack *bstack)
{
	ft_swap(&astack->value[0], &astack->value[1]);
	ft_swap(&bstack->value[0], &bstack->value[1]);
	ft_putstr_fd("ss\n", 1);
	return (0);
}

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
