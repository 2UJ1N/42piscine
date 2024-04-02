/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 21:58:20 by youjlee           #+#    #+#             */
/*   Updated: 2023/09/10 17:36:04 by youjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	change_num(long long num, long long i, char *base)
{
	if (num < 0)
	{
		write (1, "-", 1);
		num *= -1;
	}
	if (num < i)
	{
		write(1, &base[num], 1);
		return ;
	}
	else
	{
		change_num(num / i, i, base);
		change_num(num % i, i, base);
	}
}

int	chk_base(char *base)
{	
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = 0;
		while (j < i)
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long long	i;
	long long	num;

	i = chk_base(base);
	num = (long long)nbr;
	if (!(chk_base(base)))
		return ;
	if (i < 2)
		return ;
	change_num(num, i, base);
}
