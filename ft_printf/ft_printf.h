/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:43:23 by vgoret            #+#    #+#             */
/*   Updated: 2022/11/30 15:19:11 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>

char	*ft_itoa(int n);

int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_print_hexa(unsigned int nbr, const char format);
int		ft_strlen(char *str);
int		ft_print_void(long unsigned int ptr);
int		ft_print_nb(int n);
int		ft_print_unsigned(unsigned int nb);
int		ft_print_pourc(void);
int		ft_printf(const char *format, ...);

#endif