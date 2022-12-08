/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:02:59 by vgoret            #+#    #+#             */
/*   Updated: 2022/12/05 13:33:01 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*On a 3 fonctions : la 1ere va nous renvoyer la taille du nombre,
la 2eme est un itoa modifie (ne prends pas en compte les nombres
negatifs car unsigned) mais sinon fonctionne comme un itoa classique
et finalement on a la fonction qui va appeller les deux autres afin 
de print le bon nombre et return la bonne taille a la fonction printf.*/

/*ft_print_unsigned : si notre nombre est 0 on l'ecrit et on renvoi une taille
de 0. Sinon, on fait appel a un itoa modifie (pas de negatifs) pour avoir une 
chaine de characteres qu'on va ecrire grace a un ft_putstr puis free la chaine
une fois qu'on en a plus besoin. Finalement on renvoi la taille.

ft_len_num : On calcule la taille de notre nombre en regardant combien de fois
on peut le diviser par 0.

ft_presque_itoa : C'est un itoa classique (on part de la fin etc) sauf qu'il
ne gere pas les cas ou nb est negatif car unsigned.*/

#include "ft_printf.h"

int	ft_len_num(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

char	*ft_presque_itoa(unsigned int nb)
{
	char	*n;
	int		len;

	len = ft_len_num(nb);
	n = (char *)malloc(sizeof(char) * (len + 1));
	if (!n)
		return (NULL);
	n[len] = '\0';
	while (nb != 0)
	{
		n[len - 1] = nb % 10 + 48;
		nb = nb / 10;
		len--;
	}
	return (n);
}

int	ft_print_unsigned(unsigned int nb)
{
	char	*n;
	int		print_len;

	print_len = 0;
	if (nb == 0)
		print_len += write(1, "0", 1);
	else
	{
		n = ft_presque_itoa(nb);
		print_len += ft_putstr(n);
		free(n);
	}
	return (print_len);
}

/*#include <stdio.h>
int	main(void)
{
	//unsigned int nb = 42;
	//printf("\n%d\n", ft_print_unsigned(nb));
	printf("%s", ft_presque_itoa(-42));
	return (0);
}*/