/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-sarg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 02:46:52 by aes-sarg          #+#    #+#             */
/*   Updated: 2023/11/24 22:43:13 by aes-sarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_putnbr_u(unsigned int nb);
int	ft_printf(const char *str, ...);
int	ft_putstr(char *str);
int	ft_putchar(int c);
int	ft_putnbr(int n);

#endif
