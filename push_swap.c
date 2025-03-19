/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:29:36 by npederen          #+#    #+#             */
/*   Updated: 2025/03/18 19:28:32 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_picker(t_stack *astack, t_stack *bstack)
{
	if (astack->size == 3)
		sort_3(astack, bstack);
	else if (astack->size > 3 && astack->size < 6)
		sort_4_5(astack, bstack);
	else
		radix_sort_base_2(astack, bstack);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	t_stack	astack;
	t_stack	bstack;

	i = 1;
	j = 0;
	if (argc >= 3)
	{
		astack.size = argc - 1;
		bstack.size = 0;
		astack.value = malloc(sizeof(int) * (argc - 1));
		bstack.value = malloc(sizeof(int) * (argc - 1));
		if (!astack.value || !bstack.value)
			return (0);
		while (argv[i])
			astack.value[j++] = ft_atoi(argv[i++]);
		normalize(&astack);
		ft_sort_picker(&astack, &bstack);
		free(astack.value);
		free(bstack.value);
	}
	return (0);
}
