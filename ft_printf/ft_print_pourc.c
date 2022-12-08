/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pourc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:42:35 by vgoret            #+#    #+#             */
/*   Updated: 2022/11/24 16:04:01 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pourc(void)
{
	write (1, "%", 1);
	return (1);
}

/*#include <stdio.h>
int	main(void)
{
	ft_print_pourc();
	write(1, "\n", 1);
	printf(" %% ");
	return (0);
}*/