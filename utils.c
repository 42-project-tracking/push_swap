/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:22:36 by codespace         #+#    #+#             */
/*   Updated: 2023/09/26 15:00:40 by codespace        ###   ########.fr       */
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
