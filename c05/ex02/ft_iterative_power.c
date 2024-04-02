/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:48:57 by youjlee           #+#    #+#             */
/*   Updated: 2023/09/08 18:02:50 by youjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	result;

	result = 1;
	if (power == 0)
		return (1);
	else if (power < 0 || nb == 0)
		return (0);
	while (power > 0)
	{
		result *= nb;
		power --;
	}
	return (result);
}
