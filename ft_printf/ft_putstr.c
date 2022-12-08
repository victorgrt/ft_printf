/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:55:32 by vgoret            #+#    #+#             */
/*   Updated: 2022/11/25 14:39:17 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	len;

	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}

/*int	main(int ac, char **av)
{
	int i = 0;
	while (i != ac)
	{
		ft_putstr(av[i]);
		i++;
		write(1, "\n", 1);
	}
	return (0);
}*/