/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:53:32 by youjlee           #+#    #+#             */
/*   Updated: 2023/09/14 18:33:03 by youjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	plus(int n1, int n2);
int	minus(int n1, int n2);
int	multiple(int n1, int n2);
int	division(int n1, int n2);
int	modulo(int n1, int n2);

int	ft_atoi(char *str)
{
	int	sign;
	int	i;
	int	result;

	result = 0;
	sign = 1;
	i = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	while (*str == 45 || *str == 43)
	{
		if (*str == 45)
			sign *= -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		result = (*str - '0') + result * 10;
		str++;
	}
	return (sign * result);
}

void	putnbr(int nb)
{
	int	c;

	if (nb < 10)
	{
		c = nb + '0';
		write(1, &c, 1);
	}
	else
	{
		putnbr(nb / 10);
		c = nb % 10 + '0';
		write(1, &c, 1);
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb < 0)
	{
		write(1, "-", 1);
		putnbr(-nb);
	}
	else
		putnbr(nb);
}

void	print_result(int n1, int n2, char op, int (*f[5])(int, int))
{
	if (op == '+')
		ft_putnbr(f[0](n1, n2));
	else if (op == '-')
		ft_putnbr(f[1](n1, n2));
	else if (op == '*')
		ft_putnbr(f[2](n1, n2));
	else if (op == '/' && n2 == 0)
		write(1, "Stop : division by zero", 23);
	else if (op == '/')
		ft_putnbr(f[3](n1, n2));
	else if (op == '%' && n2 == 0)
		write(1, "Stop : modulo by zero", 21);
	else if (op == '%')
		ft_putnbr(f[4](n1, n2));
	else
		write(1, "0", 1);
}

int	main(int ac, char *av[])
{
	int	n1;
	int	n2;
	int	(*f[5])(int, int);

	if (ac != 4)
		return (0);
	n1 = ft_atoi(av[1]);
	n2 = ft_atoi(av[3]);
	f[0] = plus;
	f[1] = minus;
	f[2] = multiple;
	f[3] = division;
	f[4] = modulo;
	print_result(n1, n2, av[2][0], f);
	write(1, "\n", 1);
	return (0);
}
