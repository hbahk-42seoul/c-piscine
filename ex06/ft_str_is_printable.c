/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbahk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 11:20:21 by hbahk             #+#    #+#             */
/*   Updated: 2020/01/29 11:33:25 by hbahk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_printable(char *str)
{
	int i;
	int flag;

	i = 0;
	flag = 1;
	if (*str == '\0')
		return (flag);
	while (*(str + i) && flag)
	{
		if (*(str + i) >= 32 && *(str + i) <= 126)
		{
			flag = 1;
			i++;
		}
		else
			flag = 0;
	}
	return (flag);
}