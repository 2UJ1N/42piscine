/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:51:40 by youjlee           #+#    #+#             */
/*   Updated: 2023/08/27 16:12:19 by youjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_dfs(char arr[], int dep, int start, int n)
{
	if (dep == n)
	{
		write(1, arr, n);
		if (arr[0] != 10 - n + '0')
			write(1, ", ", 2);
		return ;
	}
	else
	{
		while (start <= 9)
		{
			arr[dep] = start + '0';
			ft_dfs(arr, dep + 1, start + 1, n);
			start++;
		}
	}
}

void	ft_print_combn(int n)
{
	char	arr[9];

	ft_dfs(arr, 0, 0, n);
}

/*
int	main(void)
{
	ft_print_combn(1);
	write(1, "\n", 2);
	ft_print_combn(3);
	write(1, "\n", 2);
	ft_print_combn(5);
	write(1, "\n", 2);
	ft_print_combn(7);
	write(1, "\n", 2);
	ft_print_combn(9);
}
*/
