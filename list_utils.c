/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 10:18:49 by codespace         #+#    #+#             */
/*   Updated: 2023/09/23 10:54:47 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	current = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = new;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

void	ft_lstclear(t_list **lst, void (*del)(int))
{
	t_list	*current;
	t_list	*next;

	current = *lst;
	while (current)
	{
		next = current->next;
		del(current->content);
		free(current);
		current = next;
	}
	*lst = NULL;
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current;

	current = lst;
	if (current == NULL)
	{
		return (NULL);
	}
	while (current->next != NULL)
	{
		current = current->next;
	}
	return (current);
}

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*current;

	current = lst;
	i = 0;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}

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