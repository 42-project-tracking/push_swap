/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:27:51 by abied-ch          #+#    #+#             */
/*   Updated: 2023/09/23 13:15:31 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_list **stack_a)//swap first two elements at the top of stack a
{
	t_list	*first;
	t_list	*second;
	
	if (ft_lstsize(*stack_a) < 2)
		return (-1);
	first = *stack_a;//set first to the head of list
    second = first->next;//set second to the one after first
	if (second->next != NULL)
        first->next = second->next;
    else//make first->next point to the one after second
		first->next = NULL;
	second->next = first;//make the second one point to the first, making it the new first
    *stack_a = second;//set stack_a pointer to the new first
	ft_printf("sa\n");
	return (0);
}

int	sb(t_list **stack_b)//swap first two elements at the top of stack b
{
	t_list	*first;
	t_list	*second;
	
	if (ft_lstsize(*stack_b) < 2)
		return (-1);
	first = *stack_b;//set first to the head of list
    second = first->next;//set second to the one after first
	if (second->next != NULL)
        first->next = second->next;
    else//make first->next point to the one after second
		first->next = NULL;
	second->next = first;//make the second one point to the first, making it the new first
    *stack_b = second;//set stack_a pointer to the new first
	ft_printf("sa\n");
	return (0);	
}

int	ss(t_list **stack_a, t_list **stack_b)//sa & sb at the same time
{
	if (ft_lstsize(*stack_b) < 2 || ft_lstsize(*stack_a) < 2)
		return (-1);
	sa(stack_a);
	sb(stack_b);
	ft_printf("ss\n");
	return (0);
}

int pa(t_list **stack_a, t_list **stack_b) 
{
    t_list *top_b;
    t_list *second_b;

    top_b = *stack_b;  
	if (top_b == NULL)
		return (-1); // Handle case where stack_a is empty
    second_b = top_b->next;
    *stack_a = top_b; // Corrected line to push top_a to stack_b
    *stack_b = second_b;
    top_b->next = NULL; // Make sure top_a is the new top of stack_b
    ft_printf("pa\n");
    return (0);
}

int pb(t_list **stack_a, t_list **stack_b) 
{
    t_list *top_a;
    t_list *second_a;

    top_a = *stack_a;  
	if (top_a == NULL)
		return (-1); // Handle case where stack_a is empty
    second_a = top_a->next;
    *stack_b = top_a; // Corrected line to push top_a to stack_b
    *stack_a = second_a;
    top_a->next = NULL; // Make sure top_a is the new top of stack_b
    ft_printf("pb\n");
    return (0);
}



int	ra(t_list **stack_a)//shift up all elements of a by 1, first becomes last
{
	t_list	*first;
	t_list	*last;

	if (ft_lstsize(*stack_a) < 2)
		return (-1);
	first = *stack_a;//stack_a points to the head of the stack
	last = ft_lstlast(first);//find last element
	*stack_a = first->next;//set new head to the second node
	first->next = NULL;//set first->next to NULL to make it the end of the list
	last->next = first;//last->next points to first (previously NULL), making it the new last element
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

int	rr(t_list **stack_a, t_list **stack_b)//ra & rb
{
    if (ft_lstsize((*stack_a)) < 2 || ft_lstsize((*stack_b)) < 2)
        return (-1);
    ra(stack_a);
    rb(stack_b);
    ft_printf("rr\n");
    return (0);
}

int rra(t_list **stack_a) 
{
    t_list *prev = NULL;
    t_list *last = *stack_a;
    
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
    return 0;
}

int	rrb(t_list **stack_b)//shift down b, last becomes first
{
    t_list *prev = NULL;
    t_list *last = *stack_b;
    
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
    return 0;
}

int rrr(t_list **stack_a, t_list **stack_b)// rra & rrb
{
    if (ft_lstsize((*stack_a)) < 2 || ft_lstsize((*stack_b)) < 2)
        return (-1);
    rra(stack_a);
    rrb(stack_b);
    ft_printf("rrr\n");
    return (0);
}