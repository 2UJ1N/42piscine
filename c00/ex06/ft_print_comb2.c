/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:27:00 by youjlee           #+#    #+#             */
/*   Updated: 2023/08/26 17:58:15 by youjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	first;
	int	second;

	first = 0;
	while (first <= 98)
	{
		second = first + 1;
		while (second <= 99)
		{
			ft_putchar((first / 10) + '0');
			ft_putchar((first % 10) + '0');
			write(1, " ", 1);
			ft_putchar((second / 10) + '0');
			ft_putchar((second % 10) + '0');
			if (!(first == 98 && second == 99))
				write(1, ", ", 2);
			second++;
		}
		first++;
	}
}
