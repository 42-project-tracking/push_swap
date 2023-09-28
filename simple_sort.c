/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:08:02 by abied-ch          #+#    #+#             */
/*   Updated: 2023/09/28 22:05:32 by abied-ch         ###   ########.fr       */
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

static void	ft_sort_3_args(t_list **stack_a)
{
	t_list	*top;

	top = *stack_a;
	if (top->simple == min(stack_a) && top->next->simple == max(stack_a))
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (top->simple == max(stack_a) && top->next->simple == min(stack_a))
		ra(stack_a);
	else if (top->simple == max(stack_a) && top->next->simple != min(stack_a))
	{
		ra(stack_a);
		sa(stack_a);
	}
	else if (top->simple != min(stack_a) && top->simple != max(stack_a))
	{
		if (top->next->simple == min(stack_a))
			sa(stack_a);
		else
			rra(stack_a);
	}
}

void	ft_sort_4_args(t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = ft_how_far(stack_a, min(stack_a));
	if (i == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	if (i == 1)
		ra(stack_a);
	else if (i == 3)
		rra (stack_a);
	pb(stack_a, stack_b);
	ft_sort_3_args(stack_a);
	pa(stack_a, stack_b);
}

void	ft_sort_5_args(t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = ft_how_far(stack_a, min(stack_a));
	if (i == 4)
		rra(stack_a);
	else if (i == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (i == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (i == 1)
		ra(stack_a);
	pb(stack_a, stack_b);
	ft_sort_4_args(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	ft_simple_sort(t_list **stack_a, t_list **stack_b)
{
	if (ft_is_sorted(stack_a))
		return ;
	if (ft_lstsize(*stack_a) == 2)
		sa(stack_a);
	if (ft_lstsize(*stack_a) == 3 && stack_b)
		ft_sort_3_args(stack_a);
	if (ft_lstsize(*stack_a) == 4)
		ft_sort_4_args(stack_a, stack_b);
	if (ft_lstsize(*stack_a) == 5)
		ft_sort_5_args(stack_a, stack_b);
}
