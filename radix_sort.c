/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:39:27 by codespace         #+#    #+#             */
/*   Updated: 2023/09/26 08:54:07 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_find_most_bits(t_list **stack)
{
	int		count;
	int		bits;
	t_list	*top;

	top = *stack;
	bits = 0;
	while (top)
	{
		count = top->simple;
		while (count >> bits != 0)
			bits++;
		top = top->next;
	}
	return (bits);
}

void	ft_radix_sort(t_list **stack_a, t_list **stack_b)
{
	int		max_bits;
	int		i;
	int		j;
	int		stack_size;
	t_list	*top_a;
	t_list	*top_b;
	
	top_a = *stack_a;
	top_b = *stack_b;
	max_bits = ft_find_most_bits(stack_a);
	i = 0;
	j = 0;
	stack_size = ft_lstsize(top_a);
	while (i < max_bits)
	{
		while (j < stack_size)
		{
			if (((top_a->simple >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		ft_printf("STACK B");
		ft_print_stack(*stack_b);
		while (ft_lstsize(top_b))
		{
			pa(stack_a, stack_b);
		}
		i++;
	}
}
