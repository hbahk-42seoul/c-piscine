/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbahk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 10:53:25 by hbahk             #+#    #+#             */
/*   Updated: 2020/01/29 10:55:20 by hbahk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_uppercase(char *str)
{
	int i;
	int flag;

	i = 0;
	flag = 1;
	if (*str == '\0')
		return (1);
	while (*(str + i) && flag)
	{
		if (*(str + i) >= 'A' && *(str + i) <= 'Z')
		{
			flag = 1;
			i++;
		}
		else
			flag = 0;
	}
	return (flag);
}