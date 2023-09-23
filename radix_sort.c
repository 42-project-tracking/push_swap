/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:39:27 by codespace         #+#    #+#             */
/*   Updated: 2023/09/23 18:58:17 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_most_bits(t_list **stack)
{
	int		max;
	int		bits;
	t_list	*top;

	top = *stack;
	max = top->content;
	while (top)
	{
		if (top->content > max)
			max = top->content;
		top = top->next;
	}
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}
