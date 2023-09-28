/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:08:02 by abied-ch          #+#    #+#             */
/*   Updated: 2023/09/28 18:15:23 by abied-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_sorted(t_list **stack)
{
	t_list	*top;

	top = *stack;
	while (top->next != NULL)
	{
		if (top->simple > top->next->simple)
			return (0);
		else
			top = top->next;
	}
	return (1);
}

void	ft_simple_sort(t_list **stack_a, t_list **stack_b)
{
	int		size;
	t_list	*top;
	int		min;

	min = -1;
	top = *stack_a;
	size = ft_lstsize(*stack_a);
	while (!ft_is_sorted(stack_a))
	{
		while (top)
		{
			if (min > top->simple)
				min = top->simple;
			else
				top = top->next;
		}
		while (top->simple != min)
			ra(stack_a);
		if (top->simple == min)
			pb(stack_a, stack_b);
	}
	while (ft_lstsize(*stack_b) != 0)
		pa (stack_a, stack_b);
}
