/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 20:51:05 by youjlee           #+#    #+#             */
/*   Updated: 2023/09/12 15:07:17 by youjlee          ###   ########.fr       */
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

int	cnt_arrlen(int size, char **strs, char *sep)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		if (i < size - 1)
			len += ft_strlen(sep);
		i++;
	}
	return (len);
}

char	*join_str(int size, char *result, char **strs, char *sep)
{
	int	i;
	int	j;
	int	idx;

	i = 0;
	idx = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			result[idx] = strs[i][j];
			idx++;
			j++;
		}
		j = 0;
		if (i < size - 1)
		{
			while (sep[j])
				result[idx++] = sep[j++];
		}
		i++;
	}
	result[idx] = '\0';
	return (result);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		len;
	char	*result;

	len = cnt_arrlen(size, strs, sep);
	result = (char *)malloc(len + 1);
	if (!result)
		return (0);
	return (join_str(size, result, strs, sep));
}
