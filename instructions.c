/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npederen <npederen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:37:13 by npederen          #+#    #+#             */
/*   Updated: 2025/03/14 23:27:17 by npederen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"
//sa
//sb
//ss
//pa
//pb
//ra
//rb
//rr
//rra
//rrb
//rrr

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

int	push_a(t_stack *astack, t_stack *bstack)
{
	ft_memmove(&astack->value[1], &astack->value[0], astack->size * sizeof(int));
	astack->value[0] = bstack->value[0];
	ft_memmove(&bstack->value[0], &bstack->value[1], (bstack->size - 1) * sizeof(int));
	astack->size +=1;
	bstack->size -=1;
	return(0);	
}

int	push_b(t_stack *astack, t_stack *bstack)
{
	ft_memmove(&bstack->value[1], &bstack->value[0], bstack->size * sizeof(int));
	bstack->value[0] = astack->value[0];
	ft_memmove(&astack->value[0], &astack->value[1], (astack->size - 1) * sizeof(int));
	astack->size -=1;
	bstack->size +=1;
	return(0);	
}

int	rotate_a(t_stack *astack, t_stack *bstack)
{
	int tmp;
	
	(void)bstack;
	tmp = astack->value[0];
	ft_memmove(&astack->value[0], &astack->value[1], (astack->size - 1) * sizeof(int));
	astack->value[astack->size - 1] = tmp;
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

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i != (size / 2))
	{
		ft_swap(&tab[i], &tab[size - i - 1]);
		i++;
	}
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

int main (int argc, char **argv)
{
	int		i;
	int		j;
	t_stack astack;
	t_stack bstack;

	i = 1;
	j = 0;
	if (argc >= 3)
	{
		while (argv[i])
		{
			printf("%s\n", argv[i]);
			i++;	
		}
		printf("argc: %i\n", (argc - 1));
		astack.size = argc - 1;
		bstack.size = 0;
		astack.value = malloc(sizeof(int) * (argc - 1));
		bstack.value = malloc(sizeof(int) * (argc - 1));
		i =1;
		while (argv[i])
		{
			astack.value[j] = atoi(argv[i]);
			i++;
			j++;
		}
		i = 0;
		j = 1;
		printf("tableau en int\n");
		while (argv[j])
		{
			printf("%i\n", astack.value[i]);
			i++;	
			j++;	
		}
		//ft_sort_int_tab(astack.value, (argc - 1));
		//i = 0;
		//j = 1;
		//printf("tableau en bubblesort\n");
		//while (argv[j])
		//{
		//	printf("%i\n", astack.value[i]);
		//	i++;	
		//	j++;	
		//}
		i = 0;
		j = 1;
		printf("tableau en reverse rotate\n");
		reverse_rotate_a(&astack, &bstack);
		while (argv[j])
		{
			printf("%i\n", astack.value[i]);
			i++;	
			j++;	
		}
		free(astack.value);
		free(bstack.value);
	}
	return (0);
}
