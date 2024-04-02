/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongwpa <jeongwpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 10:59:00 by jeongwpa          #+#    #+#             */
/*   Updated: 2023/08/27 14:09:31 by jeongwpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int x, int y);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_is_numeric(char *str)
{
	if (str[0] == '\0')
		return (0);
	if (str[0] == '-')
		str++;
	while (str[0] != '\0')
	{
		if (str[0] < '0' || str[0] > '9')
			return (0);
		str++;
	}
	return (1);
}

int	ft_atoi(char *str)
{
	long long int	nb;
	int				p_flag;

	p_flag = 1;
	if (str[0] == '0')
		return (0);
	if (str[0] == '-')
	{
		p_flag = -1;
		str++;
	}
	if (ft_strlen(str) > 10)
		return (0);
	nb = 0;
	while (str[0] != '\0')
	{
		nb = (nb * 10) + ((str[0] - '0') * p_flag);
		str++;
	}
	if (nb < -2147483648 || nb > 2147483647)
		return (0);
	return (nb);
}

int	main(int argc, char **argv)
{
	int	x;
	int	y;

	if (argc != 3)
	{
		write(1, "wrong input\n", sizeof(char) * 12);
		return (0);
	}
	if (ft_is_numeric(argv[1]) == 0 || ft_is_numeric(argv[2]) == 0)
	{
		write(1, "wrong input\n", sizeof(char) * 12);
		return (0);
	}
	x = ft_atoi(argv[1]);
	y = ft_atoi(argv[2]);
	rush(x, y);
	return (0);
}
