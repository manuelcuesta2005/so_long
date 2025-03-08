/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuesta- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:05:20 by mcuesta-          #+#    #+#             */
/*   Updated: 2024/10/02 11:59:27 by mcuesta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

/*
#include <stdio.h>

int	main(void)
{
	char	source[] = "hola mundo desde aqui en la luna";
	char	destination[25];

	printf("String original: '%s' ", source);
	printf("\n");
	printf("strlcpy: '%zu' ", ft_strlcpy(destination, source, 20));
	printf("\n");
	printf("new string: '%s' ", destination);
}
*/
