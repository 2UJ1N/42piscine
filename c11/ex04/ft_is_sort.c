/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:25:55 by youjlee           #+#    #+#             */
/*   Updated: 2023/09/14 20:00:15 by youjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	asc;
	int	desc;

	i = 0;
	asc = 0;
	desc = 0;
	if (length < 0)
		return (0);
	if (length <= 2)
		return (1);
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			desc++;
		if (f(tab[i], tab[i + 1]) < 0)
			asc++;
		i++;
	}
	if (asc > 0 && desc > 0)
		return (0);
	return (1);
}
