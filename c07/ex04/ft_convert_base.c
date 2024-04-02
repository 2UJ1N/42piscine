/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 21:08:50 by youjlee           #+#    #+#             */
/*   Updated: 2023/09/12 18:05:47 by youjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	chk_str_valid(char *str, int *index);
int	chk_base_valid(char *base);
int	base_len(char *base);
int	ft_atoi_base(char *str, char *base);

int	cnt_base_to_len(int nb, char *base_to)
{
	long long	n;
	int			cnt;

	n = nb;
	cnt = 1;
	if (n < 0)
	{
		n *= -1;
		cnt++;
	}
	while (n >= base_len(base_to))
	{
		n /= base_len(base_to);
		cnt++;
	}
	return (cnt);
}

char	*convert_base_from_nb(int nb, char *base_to, char *result, int cnt)
{
	long long	n;

	n = nb;
	result[cnt] = '\0';
	if (n < 0)
	{
		result[0] = '-';
		n *= -1;
	}
	while (cnt > 0)
	{
		result[cnt - 1] = base_to[n % base_len(base_to)];
		n /= base_len(base_to);
		cnt--;
		if (n == 0)
			return (result);
	}
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb;
	int		cnt;
	char	*result;

	if (!(chk_base_valid(base_from)) || (!(chk_base_valid(base_to))))
		return (0);
	nb = ft_atoi_base(nbr, base_from);
	cnt = cnt_base_to_len(nb, base_to);
	result = (char *)malloc(sizeof (char) * (cnt + 1));
	if (!result)
		return (0);
	result = convert_base_from_nb(nb, base_to, result, cnt);
	return (result);
}
