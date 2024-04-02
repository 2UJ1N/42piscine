/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 18:24:47 by youjlee           #+#    #+#             */
/*   Updated: 2023/09/03 18:24:49 by youjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		add_block(int board[4][4], int *input);
void	print_board(int board[4][4]);

void	make_board(int *input)
{
	int	row_i;
	int	col_i;
	int	board[4][4];

	row_i = 0;
	while (row_i <= 3)
	{
		col_i = 0;
		while (col_i <= 3)
		{
			board[row_i][col_i] = 0;
			col_i++;
		}
		row_i++;
	}
	if (add_block(board, input) == 1)
		print_board(board);
	else
		write(1, "Error\n", 6);
}
