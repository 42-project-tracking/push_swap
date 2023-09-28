/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abied-ch <abied-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:44:38 by codespace         #+#    #+#             */
/*   Updated: 2023/09/28 14:50:27 by abied-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_duplicates(char **arr)
{
	int		i;
	int		j;
	long	temp;

	i = -1;
	while (arr[++i])
	{
		temp = ft_atoi(arr[i]);
		j = i;
		while (arr[++j])
		{
			if (temp == ft_atoi(arr[j]))
			{
				ft_printf("Invalid Input: Duplicates\n");
				return (1);
			}
		}
	}
	return (0);
}

static int	ft_digits(char **a)
{
	int	i;
	int	j;

	i = 0;
	while (a[++i])
	{
		j = -1;
		while (a[i][++j])
		{
			if (!ft_isdigit(a[i][j]) && (a[i][j] != '+' && a[i][j] != '-'))
			{
				ft_putendl_fd("Invalid Input: Non Digit Character", 2);
				return (1);
			}
		}
	}
	return (0);
}

static int	ft_plus_minus(char **a)
{
	int	i;
	int	j;

	i = 0;
	while (a[++i])
	{
		j = -1;
		while (a[i][++j])
		{
			if (a[i][j] != ' '
					&& ((a[i][j + 1]) == '+' || (a[i][j + 1]) == '-'))
			{
				ft_putendl_fd("Invalid Input: Non-Digit Character", 2);
				return (1);
			}
			if ((a[i][j] == '-' || a[i][j] == '+') && !ft_isdigit(a[i][j + 1]))
			{
				ft_putendl_fd("Invalid Input: Non-Digit Character", 2);
				return (1);
			}
		}
	}
	return (0);
}

static int	ft_check_overflow(char **arr)
{
	long	temp;
	int		i;

	i = -1;
	while (arr[++i])
	{
		temp = ft_atoi(arr[i]);
		if (temp > 2147483647 || temp < -2147483648)
		{
			ft_putendl_fd("Invalid Input: Integer Overflow", 2);
			return (1);
		}
	}
	return (0);
}

int	ft_check_input(char **argv, int argc)
{
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
	if (ft_plus_minus(arr) || ft_digits(arr) || ft_duplicates(arr)
		|| ft_check_overflow(arr))
	{
		if (argc == 2)
			ft_free_array(arr);
		return (0);
	}
	if (argc == 2)
		ft_free_array(arr);
	return (1);
}
