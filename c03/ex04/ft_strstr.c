/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:22:55 by youjlee           #+#    #+#             */
/*   Updated: 2023/09/06 18:34:49 by youjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	fi;

	i = 0;
	if (!(to_find[i]))
		return (&str[0]);
	while (str[i])
	{
		fi = 0;
		if (str[i] == to_find[0])
		{
			while (str[i + fi] == to_find[fi])
			{
				fi++;
				if (!to_find[fi])
					return (&str[i]);
			}
		}
		i++;
	}
	return (0);
}
