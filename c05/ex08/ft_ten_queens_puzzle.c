/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:25:23 by youjlee           #+#    #+#             */
/*   Updated: 2023/09/09 17:26:07 by youjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_abs(int x)
{
	if (x < 0)
		return (x * -1);
	else
		return (x);
}

void	ft_print(char *board, int x, int *cnt)
{
	int	i;
	int	j;

	if (x == 10)
	{
		x = 0;
		while (x < 10)
			ft_putchar(board[x++] + '0');
		ft_putchar('\n');
		(*cnt)++;
		return ;
	}
	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < x && i != board[j] && ft_abs(board[j] - i) != x - j)
			j++;
		if (j >= x)
		{
			board[x] = i;
			ft_print(board, x + 1, cnt);
		}
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int		x;
	char	board[11];
	int		cnt;

	x = 0;
	cnt = 0;
	ft_print(board, x, &cnt);
	return (cnt);
}
