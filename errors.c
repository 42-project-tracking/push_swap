/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:44:38 by codespace         #+#    #+#             */
/*   Updated: 2023/09/26 16:00:42 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_check_input(char **argv, int argc)
{
	char	**arr;
	int		i;
    long   temp;
    int     j;

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
		j = -1;
		while (arr[i][++j])
		{
			temp = ft_atoi(arr[i]);
            if (temp < -2147483648 || temp > 2147483647)
            {
                ft_free_array(arr);
                ft_printf("Error: Invalid Input\n");
                return (0);
            }
			if (!ft_isdigit(arr[i][j]) && (arr[i][j] != '-' && arr[i][j] != '+'))
			{
                ft_free_array(arr);
                ft_printf("Error: Invalid Input\n");
                return (0);
            }
			if ((arr[i][j] == '-' || arr[i][j] == '+') && (!ft_isdigit(arr[i][j + 1]) && !ft_isdigit(arr[i][j + 1])))
			{
                ft_free_array(arr);
                ft_printf("Error: Invalid Input\n");
                return (0);
            }
		}
	}
	if (argc == 2)
		ft_free_array(arr);
    return (1);
}