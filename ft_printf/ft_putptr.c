/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuesta- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:51:06 by mcuesta-          #+#    #+#             */
/*   Updated: 2024/11/13 11:51:07 by mcuesta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <unistd.h>

int	ft_putptr(void *pointer)
{
	int					i;
	int					len;
	char				*hex;
	char				buffer[16];
	unsigned long long	ptr;

	hex = "0123456789abcdef";
	if (pointer == NULL)
		return (ft_putstr("(nil)"));
	i = 0;
	ptr = (unsigned long long)pointer;
	len = ft_putstr("0x");
	while (ptr > 0)
	{
		buffer[i++] = hex[ptr % 16];
		ptr /= 16;
	}
	while (i > 0)
		len += ft_putchar(buffer[--i]);
	return (len);
}
