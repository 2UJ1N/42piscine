/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:03:48 by youjlee           #+#    #+#             */
/*   Updated: 2023/09/13 14:07:44 by youjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int			i;
	long long	len;

	i = 0;
	len = max - min;
	if (len <= 0)
	{
		*range = NULL;
		return (0);
	}
	range[0] = (int *)malloc(sizeof(int) * len);
	if (range[0] == NULL)
		return (-1);
	while (min < max)
	{
		range[0][i] = min;
		i++;
		min++;
	}
	return (len);
}

/*
#include <stdio.h>
int main(void)
{
    int *range[10];
    int i;

    i = 0;
    ft_ultimate_range(range, 30, 35);
    while (i < 5)
    {
        printf("%d\n", range[0][i]);
        i++;
    }
    return (0);
}
*/
