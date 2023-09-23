/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:27:51 by abied-ch          #+#    #+#             */
/*   Updated: 2023/09/23 18:54:45 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(t_list **stack_a)
{
	t_list	*prev;
	t_list	*last;

	last = *stack_a;
	prev = NULL;
	if (ft_lstsize((*stack_a)) < 2)
		return (-1);
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	ft_printf("rra\n");
	return (0);
}

int	rrb(t_list **stack_b)
{
	t_list	*prev;
	t_list	*last;

	last = *stack_b;
	prev = NULL;
	if (ft_lstsize((*stack_b)) < 2)
		return (-1);
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
	ft_printf("rrb\n");
	return (0);
}

int	rrr(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize((*stack_a)) < 2 || ft_lstsize((*stack_b)) < 2)
		return (-1);
	rra(stack_a);
	rrb(stack_b);
	ft_printf("rrr\n");
	return (0);
}

//while i didnt find last node yet
//set prev to last
//keep iterating
//set prev->next to NULL, making it new last
//put last at beginning of the list
//point to start