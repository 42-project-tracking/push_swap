/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:41:53 by abied-ch          #+#    #+#             */
/*   Updated: 2023/09/28 11:59:45 by abied-ch         ###   ########.fr       */
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

static void	ft_create_a_list(char **argv, int argc, t_list **stack_a)
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

	if (argc < 2)
		return (-1);
	if (!ft_check_input(argv, argc))
		return (-1);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	ft_create_a_list(argv, argc, stack_a);
	ft_simplify_numbers(stack_a);
	ft_radix_sort(stack_a, stack_b);
	//ft_print_stack(*stack_a);
	ft_free_list(stack_a);
	free(stack_a);
	free(stack_b);
	return (0);
}
