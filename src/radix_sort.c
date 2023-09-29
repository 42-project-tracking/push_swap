/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:39:27 by codespace         #+#    #+#             */
/*   Updated: 2023/09/29 20:39:59 by abied-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

void	ft_name(t_list **s_a, t_list **s_b, int stack_size, int max_bits)
{
	t_list	*top_a;
	int		i;
	int		j;

	i = 0;
	top_a = *s_a;
	while (i < max_bits)
	{
		j = 0;
		while (j++ < stack_size)
		{
			top_a = *s_a;
			if (((top_a->simple >> i) & 1) == 1)
				ra(s_a);
			else
				pb(s_a, s_b);
		}
		while (ft_lstsize(*s_b) != 0)
			pa(s_a, s_b);
		i++;
	}
}

void	ft_radix_sort(t_list **stack_a, t_list **stack_b)
{
	int		max_bits;
	int		stack_size;

	if (ft_is_sorted(stack_a))
		return ;
	max_bits = ft_find_most_bits(stack_a);
	stack_size = ft_lstsize(*stack_a);
	ft_name(stack_a, stack_b, stack_size, max_bits);
}

/*sort integers by binary value, keep ones in a, push zeros
 to b, when one loop done, push back to a
 shift one bit to the right and repeat*/