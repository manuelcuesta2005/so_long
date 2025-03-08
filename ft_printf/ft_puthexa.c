/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuesta- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:34:46 by mcuesta-          #+#    #+#             */
/*   Updated: 2024/11/04 17:34:48 by mcuesta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_puthexa(unsigned int number)
{
	int		i;
	int		len;
	char	*hex;
	char	buffer[16];

	hex = "0123456789abcdef";
	if (number == 0)
		return (ft_putchar('0'));
	i = 0;
	len = 0;
	while (number > 0)
	{
		buffer[i++] = hex[number % 16];
		number /= 16;
	}
	while (i > 0)
		len += ft_putchar(buffer[--i]);
	return (len);
}

int	ft_puthexa_mayus(unsigned int number)
{
	int		i;
	int		len;
	char	*hex;
	char	*buffer[16];

	hex = "0123456789ABCDEF";
	if (number == 0)
		return (ft_putchar('0'));
	i = 0;
	len = 0;
	while (number > 0)
	{
		buffer[i++] = &hex[number % 16];
		number /= 16;
	}
	while (i > 0)
		len += ft_putchar(*buffer[--i]);
	return (len);
}
