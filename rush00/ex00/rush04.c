/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 11:16:14 by youjlee           #+#    #+#             */
/*   Updated: 2023/08/27 12:36:24 by seonggek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	check_rush04(int x, int y, int c_row, int c_col)
{
	if (c_row == 0 && c_col == 0)
		ft_putchar('A');
	else if (c_row == x - 1 && c_col == 0)
		ft_putchar('C');
	else if (c_row == 0 && c_col == y - 1)
		ft_putchar('C');
	else if (c_row == x - 1 && c_col == y - 1)
		ft_putchar('A');
	else if (c_row == 0 || c_row == x - 1 || c_col == 0 || c_col == y - 1)
		ft_putchar('B');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	i;
	int	j;

	if (x <= 0 || y <= 0)
	{
		write(1, "wrong input\n", sizeof(char) * 12);
		return ;
	}
	j = -1;
	while (++j < y)
	{
		i = -1;
		while (++i < x)
		{
			check_rush04(x, y, i, j);
		}
		ft_putchar('\n');
	}
}
