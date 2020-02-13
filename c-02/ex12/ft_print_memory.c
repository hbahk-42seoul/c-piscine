/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbahk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 22:37:33 by hbahk             #+#    #+#             */
/*   Updated: 2020/02/10 11:29:40 by hbahk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

const char	g_hex[16] = "0123456789abcdef";

void	ft_col0(long long addr_idx, long long digit)
{
	long long mod;

	if (digit == 0)
		return ;
	mod = addr_idx % 16;
	ft_col0(addr_idx / 16, digit - 1);
	write(1, &g_hex[mod], 1);
}

void	ft_col1(unsigned char *addr, long long size, long long idx)
{
	long long col_size;
	long long col_idx;

	col_size = (size - idx >= 16 ? 16 : size - idx);
	col_idx = idx;
	while (col_idx < idx + col_size)
	{
		col_idx % 2 == 0 ? write(1, " ", 1) : 0;
		write(1, &g_hex[addr[col_idx] / 16], 1);
		write(1, &g_hex[addr[col_idx] % 16], 1);
		col_idx++;
	}
	if (col_size % 2 == 1)
	{
		write(1, "  ", 2);
		col_idx++;
	}
	while (col_idx < idx + 16)
	{
		write(1, "     ", 5);
		col_idx += 2;
	}
}

void	ft_col2(unsigned char *addr, long long size, long long idx)
{
	long long col_size;
	long long col_idx;

	write(1, " ", 1);
	col_size = (size - idx >= 16 ? 16 : size - idx);
	col_idx = idx;
	while (col_idx < idx + col_size)
	{
		addr[col_idx] >= 32 && addr[col_idx] <= 126 ?
			write(1, &addr[col_idx], 1) : write(1, ".", 1);
		col_idx++;
	}
}

void	*ft_print_memory(void *addr, long long size)
{
	long long	idx;

	if (size == 0)
		return (addr);
	idx = 0;
	while (idx < size && *(long long*)(addr + idx))
		idx++;
	size = idx;
	idx = 0;
	while (idx < size)
	{
		ft_col0((long long)addr + idx, 16);
		write(1, ":", 1);
		ft_col1(addr, size, idx);
		ft_col2(addr, size, idx);
		write(1, "\n", 1);
		idx += 16;
	}
	return (addr);
}
