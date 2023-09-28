/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:41:53 by abied-ch          #+#    #+#             */
/*   Updated: 2023/09/28 19:02:58 by abied-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_array(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

static int	ft_create_a_list(char **argv, int argc, t_list **stack_a)
{
	t_list	*new;
	char	**arr;
	int		i;

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
		new = ft_lstnew(ft_atoi(arr[i]));
		ft_lstadd_back(stack_a, new);
	}
	if (argc == 2)
		ft_free_array(arr);
	return (i);
}

static void	ft_free_list(t_list **stack_a)
{
	t_list	*temp;
	t_list	*current;

	current = *stack_a;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
}

int	main(int argc, char *argv[])
{
	t_list	**stack_a;
	t_list	**stack_b;
	int		int_count;

	if (!ft_check_input(argv, argc))
		return (-1);
	stack_a = (t_list **)malloc(sizeof(t_list));
	if (!stack_a)
		return (0);
	stack_b = (t_list **)malloc(sizeof(t_list));
	if (!stack_b)
		return (free(stack_a), 0);
	*stack_a = NULL;
	*stack_b = NULL;
	int_count = ft_create_a_list(argv, argc, stack_a);
	ft_simplify_numbers(stack_a);
	//if (ft_lstsize(*stack_a) <= 5)
	//	ft_simple_sort(stack_a, stack_b);
	//else
		ft_radix_sort(stack_a, stack_b);
	ft_free_list(stack_a);
	free(stack_a);
	free(stack_b);
	return (0);
}
