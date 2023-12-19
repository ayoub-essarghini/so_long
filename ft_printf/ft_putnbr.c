/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-sarg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 02:47:37 by aes-sarg          #+#    #+#             */
/*   Updated: 2023/11/24 20:07:38 by aes-sarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int			len;
	long long	nb;

	len = 0;
	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		len += ft_putchar('-');
	}
	if (nb < 10)
	{
		len += ft_putchar(nb + '0');
	}
	else
	{
		len += ft_putnbr(nb / 10);
		len += ft_putnbr(nb % 10);
	}
	return (len);
}
