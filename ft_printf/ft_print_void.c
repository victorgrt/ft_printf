/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_void.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:45:03 by vgoret            #+#    #+#             */
/*   Updated: 2022/11/30 15:50:59 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*On commence par gere si notre nombre est 0, si c'est le cas on ecrit null et 
on renvoi 0. Sinon on ecrit un 0x pour commencer l'adresse en incrementant la 
len et on appelle notre fonction ft_hexa sur le nb en incrementant la taille.

ft_hexa : on creer notre base hexa (0-f). Si notre nombre est inferieur a 16 
alors on renvoi l'indice nb dans notre base (fait la conversion directe) en
increntant la taille. Sinon on fait un appel recursif de la fonction
avec notre nombre divise par 16 (taille base hexa) et on modulo 16 notre
nombre aussi en incrementant la len.
*/

#include "ft_printf.h"

int	ft_hexa(long unsigned int nb)
{
	char	*base;
	int		len;

	len = 0;
	base = "0123456789abcdef";
	if (nb < 16)
		len += ft_putchar(base[nb]);
	else
	{
		len += ft_hexa(nb / 16);
		len += ft_hexa(nb % 16);
	}
	return (len);
}

int	ft_print_void(long unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
	{
		len += ft_putstr("(nil)");
		return (len);
	}
	len += ft_putstr("0x");
	len += ft_hexa(nb);
	return (len);
}

/*#include <limits.h>
#include <stdio.h>
int	main(void)
{
	int res42 = ft_printf("%p\n", -1);
	int res43 = printf("%p\n", (void *)-1);
	printf("res42 : %d\nres43 : %d\n", res42, res43);
	int res5 = ft_printf("%p\n", 1);
	int res6 = printf("%p\n", (void *)1);
	printf("res5 : %d\nres6 : %d\n", res5, res6);
	int res7 = ft_printf("%p\n", 15);
	int res8 = printf("%p\n", (void *)15);
	printf("res7 : %d\nres8 : %d\n", res7, res8);
	int res9 = ft_printf("%p\n", 17);
	int res10 = printf("%p\n", (void *)17);
	printf("res9 : %d\nres10 : %d\n", res9, res10);
	int res1 = ft_printf("%p %p\n", (void *)INT_MIN, (void *)INT_MAX);
	int res2 = printf("%p %p\n",(void *)INT_MIN, (void *)INT_MAX);
	printf("res1 : %d\nres2 : %d\n", res1, res2);
	int res3 = ft_printf("%p %p\n", (void *)LONG_MIN, (void *)LONG_MAX);
	int res4 = printf("%p %p\n", (void *)LONG_MIN, (void *)LONG_MAX);
	printf("res3 : %d\nres4 : %d\n", res3, res4);
	return (0);
}*/