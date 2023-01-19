/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:31:13 by vgoret            #+#    #+#             */
/*   Updated: 2023/01/19 17:31:07 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* On utilise les macros va_start et tout car fonction variadique et donc 
si la fonction trouve un %, elle va appeler la 2eme fonction pour gere les
differents cas, et si pas de %, la fonction va juste ecrire ce qu'il faut.
Finalement, la fonction va return la taille de ce qu'elle a print.
La fonction qui va gere en fonction de ce qu'il y a
apres le % et qui va appeler une differente fonction et retourner
la taille de ce qu'elle a creer pour que ft_printf ait la bonne taille.*/

#include "ft_printf.h"

int	print_arg(va_list args, const char format)
{
	int				len;

	len = 0;
	if (format == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (format == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		len += ft_print_void(va_arg(args, long unsigned int));
	else if (format == 'd' || format == 'i')
		len += ft_print_nb(va_arg(args, int));
	else if (format == 'u')
		len += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		len += ft_print_hexa(va_arg(args, unsigned int), format);
	else if (format == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += print_arg(args, format[i + 1]);
			i++;
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}
 int	ft_print_color(char *str, char color)
{
	char	*colorfinale;

	if (color == 'R' || color == 'r')
		colorfinale = "\x1B[31m";
	if (color == 'G' || color == 'g')
		colorfinale = "\x1B[32m";
	if (color == 'Y' || color == 'y')
		colorfinale = "\x1B[33m";
	if (color == 'B' || color == 'b')
		colorfinale = "\x1B[34m";
	if (color == 'M' || color == 'm')
		colorfinale = "\x1B[35m";
	if (color == 'C' || color == 'c')
		colorfinale = "\x1B[36m";
	if (color == 'W' || color == 'w')
		colorfinale = "\x1B[37m";
	ft_printf("%s%s\n", colorfinale, str);
	return (ft_strlen(str));
}

int	ft_print_rainbow(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i % 3 == 0)
			ft_printf("%s%c", "\x1B[32m", str[i]);
		else if (i % 5 == 0)
			ft_printf("%s%c", "\x1B[36m", str[i]);
		else if (i % 7 == 0)
			ft_printf("%s%c", "\x1B[35m", str[i]);
		else
			ft_printf("%s%c", "\x1B[36m", str[i]);
		i++;
	}
	write(1, "\n", 1);
	return (ft_strlen(str));
}

#include <stdio.h>
int main(void)
{
	ft_print_rainbow("Nec minus feminae quoque calamitatum partici\
	pes fuere similium. nam ex hoc quoque sexu peremptae sunt \
	originis altae conplures, adulteriorum flagitiis obnoxiae vel \
	stuprorum. inter quas notiores fuere Claritas et Flaviana, \
	quarum altera cum duceretur ad mortem, indumento, quo vestita \
	erat, abrepto, ne velemen quidem secreto membrorum sufficiens \
	retinere permissa est. ideoque carnifex nefas admisisse \
	convictus inmane, vivus exustus est.");
    return 0;
}

// int	main(void)
// {	char str[] = "Hello World";
// 	ft_printf("%s", str);
// 	return (0);
// }
