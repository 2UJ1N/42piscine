/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 20:22:40 by youjlee           #+#    #+#             */
/*   Updated: 2023/09/05 14:46:17 by youjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_addr(unsigned long long addr)
{
	int		i;
	char	hex[16];

	i = 15;
	while (i >= 0)
	{
		hex[i] = "0123456789abcdef"[addr % 16];
		addr /= 16;
		i--;
	}
	write(1, hex, 16);
	write(1, ":", 1);
}

void	print_hex(unsigned char *addr, unsigned int len)
{
	unsigned int	i;

	i = 0;
	while (i < len)
	{
		if (!(i % 2))
			write(1, " ", 1);
		write(1, &"0123456789abcdef"[addr[i] / 16], 1);
		write(1, &"0123456789abcdef"[addr[i] % 16], 1);
		i++;
	}
	while (i < 16)
	{
		if (!(i++ % 2))
			write(1, " ", 1);
		write(1, "  ", 2);
	}
}

void	print_str(unsigned char	*addr, unsigned int len)
{
	unsigned int	i;

	i = 0;
	write(1, " ", 1);
	while (i < len)
	{
		if (addr[i] >= 32 && addr[i] <= 126)
			write(1, &addr[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	len;

	while (size)
	{
		if (size / 16)
			len = 16;
		else
			len = size % 16;
		print_addr((unsigned long long)addr);
		print_hex(addr, len);
		print_str(addr, len);
		write(1, "\n", 1);
		addr += 16;
		size -= len;
	}
	return (addr);
}
