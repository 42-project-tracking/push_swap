/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:39:27 by codespace         #+#    #+#             */
/*   Updated: 2023/09/28 22:12:54 by abied-ch         ###   ########.fr       */
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

	if (ft_is_sorted(stack_a))
		return ;
	top_a = *stack_a;
	max_bits = ft_find_most_bits(stack_a);
	i = 0;
	stack_size = ft_lstsize(*stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < stack_size)
		{
			top_a = *stack_a;
			if (((top_a->simple >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (ft_lstsize(*stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}
