/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:37:40 by youjlee           #+#    #+#             */
/*   Updated: 2023/08/25 18:40:10 by youjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	char	po;
	char	ne;

	po = 'P';
	ne = 'N';
	if (n < 0)
		write(1, &ne, 1);
	else
		write(1, &po, 1);
}
