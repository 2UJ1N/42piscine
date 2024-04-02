/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 18:59:13 by youjlee           #+#    #+#             */
/*   Updated: 2023/09/10 17:38:11 by youjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	long long	i;

	i = 3;
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	else if (nb % 2 == 0)
		nb++;
	while (nb % 2 == 1)
	{
		if (ft_is_prime(nb))
			return (nb);
		nb += 2;
	}
	return (0);
}
