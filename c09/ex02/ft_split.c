/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 21:09:38 by youjlee           #+#    #+#             */
/*   Updated: 2023/09/12 21:09:44 by youjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	chk_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	cnt_word(char	*str, char *charset)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] && chk_charset(str[i], charset))
			i++;
		if (str[i] && !(chk_charset(str[i], charset)))
			cnt++;
		while (str[i] && !(chk_charset(str[i], charset)))
			i++;
	}
	return (cnt);
}

int	word_len(char *str, char *charset)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i] != '\0' && !(chk_charset(str[i], charset)))
	{
		if (chk_charset(str[i], charset))
			break ;
		cnt++;
		i++;
	}
	return (cnt);
}

char	*ft_strdup(char	*src, char	*charset)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *)malloc(sizeof(char) * word_len(src, charset) + 1);
	if (!dest)
		return (0);
	while (i < word_len(src, charset))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		cnt;
	int		i;

	i = 0;
	cnt = cnt_word(str, charset);
	result = (char **)malloc(sizeof (char *) * (cnt + 1));
	if (!result)
		return (0);
	while (i < cnt)
	{
		while (chk_charset(*str, charset))
			str++;
		result[i] = ft_strdup(str, charset);
		str += word_len(str, charset);
		i++;
	}
	result[i] = 0;
	return (result);
}
