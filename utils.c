/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:22:36 by codespace         #+#    #+#             */
/*   Updated: 2023/09/28 21:58:45 by abied-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_list *first)
{
	t_list	*tmp;

	tmp = first;
	while (tmp != NULL)
	{
		ft_printf("%d\n", tmp->content);
		tmp = tmp->next;
	}
}

void	ft_print_simple_stack(t_list *first)
{
	t_list	*tmp;

	tmp = first;
	while (tmp != NULL)
	{
		ft_printf("%d\n", tmp->simple);
		tmp = tmp->next;
	}
}

int	min(t_list **stack)
{
	int		min;
	t_list	*top;

	top = *stack;
	min = ft_lstsize(*stack) + 1;
	while (top)
	{
		if (min > top->simple)
			min = top->simple;
		top = top->next;
	}
	return (min);
}

int	max(t_list **stack)
{
	int		max;
	t_list	*top;

	top = *stack;
	max = -1;
	while (top)
	{
		if (max < top->simple)
			max = top->simple;
		top = top->next;
	}
	return (max);
}

int	ft_how_far(t_list **stack, int search)
{
	t_list	*top;
	int		i;

	top = *stack;
	i = 0;
	while (top)
	{
		if (top->simple == search)
			return (i);
		top = top->next;
		i++;
	}
	return (0);
}
