/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:40:32 by codespace         #+#    #+#             */
/*   Updated: 2023/09/29 20:39:42 by abied-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	sa(t_list **stack_a)
{
	t_list	*first;
	t_list	*second;

	if (ft_lstsize(*stack_a) < 2)
		return (-1);
	first = *stack_a;
	second = first->next;
	if (second->next != NULL)
		first->next = second->next;
	else
		first->next = NULL;
	second->next = first;
	*stack_a = second;
	ft_printf("sa\n");
	return (0);
}

int	sb(t_list **stack_b)
{
	t_list	*first;
	t_list	*second;

	if (ft_lstsize(*stack_b) < 2)
		return (-1);
	first = *stack_b;
	second = first->next;
	if (second->next != NULL)
		first->next = second->next;
	else
		first->next = NULL;
	second->next = first;
	*stack_b = second;
	ft_printf("sa\n");
	return (0);
}

int	ss(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_b) < 2 || ft_lstsize(*stack_a) < 2)
		return (-1);
	sa(stack_a);
	sb(stack_b);
	ft_printf("ss\n");
	return (0);
}
//swap first two elements at the top of stack a
//set first to the head of list
//set second to the one after first
//make first->next point to the one after second
//make the second one point to the first, making it the new first
//set stack_a pointer to the new first