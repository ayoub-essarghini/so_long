/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-sarg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 02:46:09 by aes-sarg          #+#    #+#             */
/*   Updated: 2023/11/24 22:47:47 by aes-sarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long nb, int base)
{
	int	len;

	len = 0;
	if (nb < 16)
	{
		if (nb < 10)
			len += ft_putchar(nb + 48);
		else
		{
			if (base == 1)
				len += ft_putchar(nb + 87);
			else
				len += ft_putchar(nb + 55);
		}
	}
	if (nb >= 16)
	{
		len += ft_putnbr_base(nb / 16, base);
		len += ft_putnbr_base(nb % 16, base);
	}
	return (len);
}

int	ft_option(char c, va_list list)
{
	if (c == 'c')
		return (ft_putchar(va_arg(list, int)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(list, int)));
	else if (c == 'u')
		return (ft_putnbr_u(va_arg(list, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(list, char *)));
	else if (c == 'x')
		return (ft_putnbr_base(va_arg(list, unsigned int), 1));
	else if (c == 'X')
		return (ft_putnbr_base(va_arg(list, unsigned int), 2));
	else if (c == 'p')
	{
		ft_putstr("0x");
		return (2 + ft_putnbr_base(va_arg(list, unsigned long int), 1));
	}
	else if (c == '%')
	{
		return (ft_putchar('%'));
	}
	else
		return (ft_putchar(c));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		i;
	int		len;

	va_start(list, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] != '%')
			len += ft_putchar(str[i]);
		else if (str[i + 1])
		{
			len += ft_option(str[i + 1], list);
			i++;
		}
		i++;
	}
	va_end(list);
	return (len);
}

// # define STR " %d ", 10
// int main()
// {
// 	ft_printf(STR);
// 	printf("\n");
//     printf(STR);
// 	printf("\n");
// }
