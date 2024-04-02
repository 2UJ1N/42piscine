/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:47:41 by youjlee           #+#    #+#             */
/*   Updated: 2023/09/01 18:13:01 by youjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	di;
	unsigned int	si;

	di = 0;
	si = 0;
	while (dest[di])
		di++;
	while (src[si] && si < nb)
	{
		dest[di + si] = src[si];
		si++;
	}
	dest[di + si] = '\0';
	return (dest);
}
