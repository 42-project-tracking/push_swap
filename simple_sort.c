/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:08:02 by abied-ch          #+#    #+#             */
/*   Updated: 2023/09/28 17:09:24 by abied-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_simple_sort(t_list **stack_a, t_list **stack_b)
{
	if (stack_a || stack_b)
		ft_radix_sort(stack_a, stack_b);
}

