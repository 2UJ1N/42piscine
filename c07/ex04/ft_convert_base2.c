/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 21:09:51 by youjlee           #+#    #+#             */
/*   Updated: 2023/09/12 15:05:02 by youjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	chk_str_valid(char *str, int *index)
{
	int	sign;
	int	result;
	int	i;

	sign = 1;
	result = 0;
	i = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	*index = i - 1;
	return (sign);
}

int	chk_base_valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (!base[0] || !base[1])
		return (0);
	while (base[i])
	{
		if ((9 <= base[i] && base[i] <= 13)
			|| base[i] == 32 || base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	base_len(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	j;
	int	result;
	int	i;
	int	sign;

	result = 0;
	sign = chk_str_valid(str, &i);
	if (!(chk_base_valid(base)))
		return (0);
	while (str[++i])
	{
		j = -1;
		while (base[++j])
		{
			if (str[i] == base[j])
			{
				result = result * base_len(base) + j;
				break ;
			}
		}
		if (base[j] == 0)
			return (result * sign);
	}
	return (result * sign);
}
