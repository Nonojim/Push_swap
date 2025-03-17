/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:29:36 by npederen          #+#    #+#             */
/*   Updated: 2025/03/17 13:57:33 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

int	main (int argc, char **argv)
{
	int		i;
	int		j;
	t_stack astack;
	t_stack bstack;

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
		{
			astack.value[j] = atoi(argv[i]);
			i++;
			j++;
		}
		normalize(&astack);
		radix_sort_base_2(&astack, &bstack);
		i = 0;
		j = 1;
		//printf("tableau sous radix\n");
		while (argv[j])
		{
			//printf("%i\n", astack.value[i]);
			i++;
			j++;
		}
		free(astack.value);
		free(bstack.value);
	}
	return (0);
}
