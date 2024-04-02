/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_block.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 18:24:55 by youjlee           #+#    #+#             */
/*   Updated: 2023/09/03 18:24:56 by youjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	chk_board(int board[4][4], int *inputs);

int	chk_0(int board[4][4], int *row_i, int *col_i)
{
	*row_i = 0;
	while (*row_i <= 3)
	{
		*col_i = 0;
		while (*col_i <= 3)
		{
			if (board[*row_i][*col_i] == 0)
				return (1);
			(*col_i)++;
		}
		(*row_i)++;
	}
	return (0);
}

int	col_red(int board[4][4], int col, int h)
{
	int	row_i;

	row_i = 0;
	while (row_i <= 3)
	{
		if (board[row_i][col] == h)
			return (1);
		row_i++;
	}
	return (0);
}

int	row_red(int board[4][4], int row, int h)
{
	int	col_i;

	col_i = 0;
	while (col_i <= 3)
	{
		if (board[row][col_i] == h)
			return (1);
		col_i++;
	}
	return (0);
}

int	check_red(int board[4][4], int row, int col, int h)
{
	if ((row_red(board, row, h) == 0)
		&& (col_red(board, col, h) == 0))
		return (0);
	return (1);
}

int	add_block(int board[4][4], int *input)
{
	int	box_h;
	int	row;
	int	col;

	if ((chk_0(board, &row, &col) == 0)
		&& (chk_board(board, input) == 1))
		return (1);
	if (row == 4 && col == 4)
		return (0);
	box_h = 1;
	while (box_h <= 4)
	{
		if (check_red(board, row, col, box_h) == 0)
		{
			board[row][col] = box_h;
			if (add_block(board, input) == 1)
				return (1);
			board[row][col] = 0;
		}
		box_h++;
	}
	return (0);
}
