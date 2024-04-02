/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_board.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 18:24:34 by youjlee           #+#    #+#             */
/*   Updated: 2023/09/03 18:24:37 by youjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	chk_col_plus(int board[4][4], int input, int col)
{
	int	row_i;
	int	cnt;
	int	max;

	row_i = 1;
	cnt = 1;
	max = board[0][col];
	while (row_i <= 3)
	{
		if (board[row_i][col] > max)
		{
			max = board[row_i][col];
			cnt++;
		}
		row_i++;
	}
	if (cnt == input)
		return (1);
	return (0);
}

int	chk_col_minus(int board[4][4], int input, int col)
{
	int	row_i;
	int	cnt;
	int	max;

	row_i = 2;
	cnt = 1;
	max = board[3][col];
	while (row_i >= 0)
	{
		if (board[row_i][col] > max)
		{
			max = board[row_i][col];
			cnt++;
		}
		row_i--;
	}
	if (cnt == input)
		return (1);
	return (0);
}

int	chk_row_plus(int board[4][4], int input, int row)
{
	int	col_i;
	int	cnt;
	int	max;

	col_i = 1;
	cnt = 1;
	max = board[row][0];
	while (col_i <= 3)
	{
		if (board[row][col_i] > max)
		{
			max = board[row][col_i];
			cnt++;
		}
		col_i++;
	}
	if (cnt == input)
		return (1);
	return (0);
}

int	chk_row_minus(int board[4][4], int input, int row)
{
	int	col_i;
	int	cnt;
	int	max;

	col_i = 2;
	cnt = 1;
	max = board[row][3];
	while (col_i >= 0)
	{
		if (board[row][col_i] > max)
		{
			max = board[row][col_i];
			cnt++;
		}
		col_i--;
	}
	if (cnt == input)
		return (1);
	return (0);
}

int	chk_board(int board[4][4], int *input)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (chk_col_plus(board, input[i], i)
			&& chk_col_minus(board, input[i + 4], i)
			&& chk_row_plus(board, input[i + 8], i)
			&& chk_row_minus(board, input[i + 12], i))
			i++;
		else
			return (0);
	}
	return (1);
}
