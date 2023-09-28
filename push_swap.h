/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:42:40 by abied-ch          #+#    #+#             */
/*   Updated: 2023/09/28 22:12:24 by abied-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_list
{
	int				content;
	int				simple;
	struct s_list	*next;
}	t_list;

void	ft_print_error(char *error_message);
int		main(int argc, char *argv[]);
t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);

int		ra(t_list **stack_a);
int		rb(t_list **stack_b);
int		rr(t_list **stack_a, t_list **stack_b);
int		rra(t_list **stack_a);
int		rrb(t_list **stack_b);
int		rrr(t_list **stack_a, t_list **stack_b);
int		sa(t_list **stack_a);
int		sb(t_list **stack_b);
int		ss(t_list **stack_a, t_list **stack_b);
int		pa(t_list **stack_a, t_list **stack_b);
int		pb(t_list **stack_a, t_list **stack_b);

void	ft_free_array(char **arr);
void	ft_print_stack(t_list *first);
void	ft_simplify_numbers(t_list **stack);
void	ft_print_simple_stack(t_list *first);
void	ft_radix_sort(t_list **stack_a, t_list **stack_b);
int		ft_check_input(char **argv, int argc);
void	ft_simple_sort(t_list **stack_a, t_list **stack_b);
int		min(t_list **stack);
int		max(t_list **stack);
int		ft_how_far(t_list **stack, int search);
int		ft_is_sorted(t_list **stack);

#endif