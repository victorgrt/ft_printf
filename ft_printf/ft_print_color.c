/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:14:19 by vgoret            #+#    #+#             */
/*   Updated: 2023/01/19 17:29:07 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	ft_print_color(char *str, char color)
// {
// 	char	*colorfinale;

// 	if (color == 'R' || color == 'r')
// 		colorfinale = "\x1B[31m";
// 	if (color == 'G' || color == 'g')
// 		colorfinale = "\x1B[32m";
// 	if (color == 'Y' || color == 'y')
// 		colorfinale = "\x1B[33m";
// 	if (color == 'B' || color == 'b')
// 		colorfinale = "\x1B[34m";
// 	if (color == 'M' || color == 'm')
// 		colorfinale = "\x1B[35m";
// 	if (color == 'C' || color == 'c')
// 		colorfinale = "\x1B[36m";
// 	if (color == 'W' || color == 'w')
// 		colorfinale = "\x1B[37m";
// 	ft_printf("%s%s\n", colorfinale, str);
// 	return (ft_strlen(str));
// }

// int	ft_print_rainbow(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (i % 3 == 0)
// 			ft_printf("%s%c", "\x1B[32m", str[i]);
// 		else if (i % 5 == 0)
// 			ft_printf("%s%c", "\x1B[36m", str[i]);
// 		else if (i % 7 == 0)
// 			ft_printf("%s%c", "\x1B[35m", str[i]);
// 		else
// 			ft_printf("%s%c", "\x1B[36m", str[i]);
// 		i++;
// 	}
// 	write(1, "\n", 1);
// 	return (ft_strlen(str));
// }

// #include <stdio.h>
// int main(void)
// {
// 	ft_print_rainbow("Nec minus feminae quoque calamitatum partici\
// 	pes fuere similium. nam ex hoc quoque sexu peremptae sunt \
// 	originis altae conplures, adulteriorum flagitiis obnoxiae vel \
// 	stuprorum. inter quas notiores fuere Claritas et Flaviana, \
// 	quarum altera cum duceretur ad mortem, indumento, quo vestita \
// 	erat, abrepto, ne velemen quidem secreto membrorum sufficiens \
// 	retinere permissa est. ideoque carnifex nefas admisisse \
// 	convictus inmane, vivus exustus est.");
//     return 0;
// }
