/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:49:06 by vgoret            #+#    #+#             */
/*   Updated: 2022/11/30 16:26:09 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_print_hexa : si notre num est 0 on va juste write un 0. Sinon
on fait appel a ft_put_hexa pour convertir nore nombre en hexa puis
on return la taille obtenue grace a ft_hexa_len.

ft_put_hexa : Si notre nombre est supp a 16, il faut modulo et 
diviser par 16 avec un appel recursif pour avoir un nombre "convertissable".
Une fois que c'est le cas, si notre num est inf a 10, on ecrit le nombre
+ '0' (base 10) sinon en fonction de x ou X, on converti
notre nombre en hexa en faisant - 10 + 'a'.

ft_hexa_len : renvoi la taille d'un nombre en le divisant par 16 et incrementant
a chaque fois. 
*/

#include "ft_printf.h"

int	ft_hexa_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_hexa(unsigned int num, const char format)
{
	if (num >= 16)
	{
		ft_put_hexa(num / 16, format);
		ft_put_hexa(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_putchar(num + '0');
		else
		{
			if (format == 'x')
				ft_putchar(num - 10 + 'a');
			if (format == 'X')
				ft_putchar(num - 10 + 'A');
		}
	}
}

int	ft_print_hexa(unsigned int num, const char format)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_put_hexa(num, format);
	return (ft_hexa_len(num));
}

/*int	ft_putnbr_base(int nbr, char *base)
{
	long int	len;
	long int	nb;
	long int	modulo;
	long int	division;

	if (!nbr)
		len = 0;
	len = 1;
	nb = nbr;
	if (nb < 0)
	{
		nb = nb * (-1);
		len++;
	}
	division = nb / 16;
	modulo = nb % 16;
	if (division != 0)
	{
		len += ft_putnbr_base(division, base);
	}
	write(1, &base[modulo], 1);
	return (len);
}

#include <limits.h>
#include <stdio.h>
int main(void)
{
	int nbr = -11;
	//int b = printf("%x", nbr);
	printf("test : %x\n", nbr);
	//printf("\n%d\n", b);
	char base[] = "0123456789abcdef";
	int a = ft_putnbr_base(nbr, base);
	printf("\n%d", a);

	
	return (0);
}
*/