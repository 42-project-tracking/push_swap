/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplify.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:13:51 by codespace         #+#    #+#             */
/*   Updated: 2023/09/28 22:24:19 by abied-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*ft_find_next_smallest(t_list **stack)
{
	t_list	*top;
	t_list	*min;

	top = *stack;
	min = NULL;
	while (top)
	{
		if (top->simple == -1 && (min == NULL || top->content < min->content))
			min = top;
		top = top->next;
	}
	return (min);
}

void	ft_simplify_numbers(t_list **stack)
{
	int		simp;
	t_list	*top;

	top = ft_find_next_smallest(stack);
	simp = 0;
	while (top)
	{
		top->simple = simp++;
		top = ft_find_next_smallest(stack);
	}
}

/*radix only works for positive numbers, therefore I add
an extra "simple" content spot to my struct, and i set it to the position
of my actual content based on its value compared to other nodes, 
then I just sort using simple*/