/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:44:39 by youjlee           #+#    #+#             */
/*   Updated: 2023/08/27 15:50:50 by youjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	num_arr[3];
	char	sep_arr[2];

	sep_arr[0] = ',';
	sep_arr[1] = ' ';
	num_arr[0] = '0';
	while (num_arr[0] <= '7')
	{
		num_arr[1] = num_arr[0] + 1;
		while (num_arr[1] <= '8')
		{
			num_arr[2] = num_arr[1] + 1;
			while (num_arr[2] <= '9')
			{
				write(1, &num_arr, 3);
				if (num_arr[0] != '7')
					write(1, &sep_arr, 2);
				num_arr[2]++;
			}
			num_arr[1]++;
		}
		num_arr[0]++;
	}
}
