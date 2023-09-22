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

static void	ft_free_array(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

static void	ft_create_a_list(char **argv, int argc, t_list **stack_a)
{
	t_list	*new;
	char	**arr;
	int		i;
	int		*int_ptr;

	i = -1;
	if (argc == 2)
		arr = ft_split(argv[1], ' ');
	else
	{
		i = 0;
		arr = argv;
	}
	while (arr[++i])
	{
		int_ptr = malloc(sizeof(int));
		*int_ptr = ft_atoi(arr[i]);
		new = ft_lstnew(int_ptr);
		ft_lstadd_back(stack_a, new);
	}
	if (argc == 2)
		ft_free_array(arr);
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
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc < 2)
		return (-1);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	ft_create_a_list(argv, argc, stack_a);
	while ((*stack_a))
	{
		ft_printf("%d\n", *((int *)(*stack_a)->content));
		*stack_a = (*stack_a)->next;
	}
	ft_printf("\na     b\n");
	return (0);
}
