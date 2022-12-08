/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:31:13 by vgoret            #+#    #+#             */
/*   Updated: 2022/12/08 14:43:15 by vgoret           ###   ########.fr       */
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

int	main(void)
{	char str[] = "Hello World";
	ft_printf("%s", str);
	return (0);
}
