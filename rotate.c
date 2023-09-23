/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:46:30 by codespace         #+#    #+#             */
/*   Updated: 2023/09/23 18:48:32 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_list **stack_a)
{
	t_list	*first;
	t_list	*last;

	if (ft_lstsize(*stack_a) < 2)
		return (-1);
	first = *stack_a;
	last = ft_lstlast(first);
	*stack_a = first->next;
	first->next = NULL;
	last->next = first;
	ft_printf("ra\n");
	return (0);
}

int	rb(t_list **stack_b)
{
	t_list	*first;
	t_list	*last;

	if (ft_lstsize(*stack_b) < 2)
		return (-1);
	first = *stack_b;
	last = ft_lstlast(first);
	*stack_b = first->next;
	first->next = NULL;
	last->next = first;
	ft_printf("rb\n");
	return (0);
}

int	rr(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize((*stack_a)) < 2 || ft_lstsize((*stack_b)) < 2)
		return (-1);
	ra(stack_a);
	rb(stack_b);
	ft_printf("rr\n");
	return (0);
}

//shift up all elements of a by 1, first becomes last
//stack_a points to the head of the stack
//find last element
//set new head to the second node
//set first->next to NULL to make it the end of the list
//last->next points to first (previously NULL), making it the new last element