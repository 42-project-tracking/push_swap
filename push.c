/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:43:34 by codespace         #+#    #+#             */
/*   Updated: 2023/09/23 18:45:55 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*top_b;
	t_list	*second_b;

	top_b = *stack_b;
	if (top_b == NULL)
		return (-1);
	second_b = top_b->next;
	*stack_a = top_b;
	*stack_b = second_b;
	top_b->next = NULL;
	ft_printf("pa\n");
	return (0);
}

int	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*top_a;
	t_list	*second_a;

	top_a = *stack_a;
	if (top_a == NULL)
		return (-1);
	second_a = top_a->next;
	*stack_b = top_a;
	*stack_a = second_a;
	top_a->next = NULL;
	ft_printf("pb\n");
	return (0);
}
