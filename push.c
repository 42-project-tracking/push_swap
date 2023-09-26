/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:43:34 by codespace         #+#    #+#             */
/*   Updated: 2023/09/26 13:26:54 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*top_a;
	t_list	*top_b;

	if (ft_lstsize(*stack_a) == 0)
		return (-1);
	top_b = *stack_b;
	top_a = *stack_a;
	tmp = top_a;
	top_a = top_a->next;
	*stack_a = top_a;
	if (!top_b)
	{
		top_b = tmp;
		top_b->next = NULL;
		*stack_b = top_b;
	}
	else
	{
		tmp->next = top_b;
		*stack_b = tmp;
	}
	ft_printf("pb\n");
	return (0);
}

int	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*top_a;
	t_list	*top_b;

	if (ft_lstsize(*stack_b) == 0)
		return (-1);
	top_a = *stack_a;
	top_b = *stack_b;
	tmp = top_b;
	top_b = top_b->next;
	*stack_b = top_b;
	if (!top_a)
	{
		top_a = tmp;
		top_a->next = NULL;
		*stack_a = top_a;
	}
	else
	{
		tmp->next = top_a;
		*stack_a = tmp;
	}
	ft_printf("pa\n");
	return (0);
}
