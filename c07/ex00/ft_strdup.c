/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:46:25 by youjlee           #+#    #+#             */
/*   Updated: 2023/09/09 17:52:31 by youjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	cnt;

	cnt = 0;
	while (str[cnt] != 0)
		cnt++;
	return (cnt);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*result;

	i = 0;
	result = malloc((ft_strlen(src) + 1) * sizeof (char));
	if (!result)
		return (0);
	while (src[i])
	{
		result[i] = src[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
