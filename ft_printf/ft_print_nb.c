/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:10:21 by vgoret            #+#    #+#             */
/*   Updated: 2022/11/30 16:31:13 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_print_nb : Pour ecrire notre nombre on a besoin de le convertir en une 
chaine de characteres. Pour ca on utilise un itoa classique qu'on va stocker 
dans notre variable. On rentre ft_print_str dans une variable qu'on return
apres avoir free la chaine de characteres.

ft_print_str : Cette fonction va nous servir a ecrire notre chaine de characteres
avec un ft_putstr/write classique ainsi que de calculer la taille de 
notre chaine, que la fonction va renvoyer. 
*/

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[i])
	{	
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_print_nb(int n)
{
	char	*nb;
	int		len;

	len = 0;
	nb = ft_itoa(n);
	len = ft_print_str(nb);
	free(nb);
	return (len);
}

/*#include <stdio.h>
#include <limits.h>
int	main(void)
{
	int	nb = 0;
	int	nnb = INT_MIN;
	ft_print_nb(nb);
	printf("\n");
	ft_print_nb(nnb);
	return (0);
}*/