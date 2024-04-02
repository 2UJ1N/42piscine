/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:53:47 by youjlee           #+#    #+#             */
/*   Updated: 2023/09/09 18:20:49 by youjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int			i;
	int			*result;
	long long	len;

	i = 0;
	len = max - min;
	if (len <= 0)
		return (0);
	result = (int *)malloc(sizeof(int) * len);
	if (result == NULL)
		return (0);
	while (i < len)
	{
		result[i] = i + min;
		i++;
	}
	return (result);
}
