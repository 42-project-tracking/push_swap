/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:41:53 by abied-ch          #+#    #+#             */
/*   Updated: 2023/09/21 20:43:32 by abied-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_create_a_list(char **arr)
{
	int		i;
	t_list	*stack_a;
	t_list	*temp;
	int		*int_ptr;

	i = 1;
	stack_a = NULL;
	while (arr[i])
	{
		int_ptr = malloc(sizeof(int));
		*int_ptr = ft_atoi(arr[i]);
		temp = ft_lstnew(int_ptr);
		ft_lstadd_front(&stack_a, temp);
		i++;
	}
	return (stack_a);
}

t_list	*ft_create_b_list(unsigned int size)
{
	t_list			*stack_b;
	t_list			*temp;
	unsigned int	i;

	i = 0;
	while (i <= size)
	{
		temp = ft_lstnew(NULL);
		ft_lstadd_front(&stack_b, temp);
		i++;
	}
	return (stack_b);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	//t_list	*stack_b;
	//t_list	*temp;

	stack_a = NULL;
	//stack_b = NULL;
	stack_a = ft_create_a_list(argv);
	//temp = stack_a;
	//stack_b = ft_create_b_list(6);
	if (argc)
	{
		while (stack_a)
		{
			ft_printf("%d\n", *((int *)stack_a->content));
			stack_a = stack_a->next;
		}
		ft_printf("\na     b\n");
	}
	return (0);
}
