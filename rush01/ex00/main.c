/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 18:11:17 by youjlee           #+#    #+#             */
/*   Updated: 2023/09/03 18:11:23 by youjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	make_board(int *inputs);

int	check_input(char *argv)
{
	int	idx;

	idx = 0;
	while (argv[idx])
	{
		if ((idx % 2 == 0 && (argv[idx] >= '1' && argv[idx] <= '4'))
			|| (idx % 2 == 1 && argv[idx] == ' '))
			idx++;
		else
			return (0);
	}
	if (idx == 31)
		return (1);
	return (0);
}

void	change_input(char *argv, int *input)
{
	int	argv_idx;
	int	input_idx;

	argv_idx = 0;
	input_idx = 0;
	while (argv[argv_idx] != '\0')
	{	
		if (argv[argv_idx] == ' ')
			argv_idx++;
		input[input_idx] = argv[argv_idx] - '0';
		input_idx++;
		argv_idx++;
	}
}

int	main(int argc, char **argv)
{
	int		input[16];

	if (argc == 2 && check_input(argv[1]) == 1)
	{
		change_input(argv[1], input);
		make_board(input);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
