/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbahk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 06:10:21 by hbahk             #+#    #+#             */
/*   Updated: 2020/01/29 06:59:26 by hbahk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int flag;
	int i;
	int j;
	int temp;

	flag = 1;
	i = size - 1;
	while (flag)
	{
		flag = 0;
		j = 0;
		while (j < i)
		{
			if (tab[j] > tab[j + 1])
			{
				temp = tab[j + 1];
				tab[j + 1] = tab[j];
				tab[j] = temp;
				flag = 1;
			}
			j++;
		}
		i--;
	}
}
