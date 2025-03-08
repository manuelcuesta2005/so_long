/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuesta- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:05:18 by mcuesta-          #+#    #+#             */
/*   Updated: 2024/10/02 12:05:05 by mcuesta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	len_str;
	char	*substring;

	i = 0;
	len_str = ft_strlen(s);
	if (start >= len_str)
	{
		return (ft_strdup(""));
	}
	if (len > len_str - start)
		len = len_str - start;
	substring = (char *)malloc((len + 1) * sizeof(char));
	if (substring == NULL)
		return (NULL);
	while (i < len)
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}

/*
#include <stdio.h>

int	main(void)
{
	const char* original = "Hola, Mundo!";
	char* copia = ft_substr(original, 0, 5);
	if (copia == NULL) {
		printf("Error: No se pudo duplicar la cadena.\n");
		return (1); // Salimos con un código de error
	}
	printf("Cadena original: %s\n", original);
	printf("Cadena duplicada: %s\n", copia);
	// Liberar la memoria asignada para la cadena duplicada
	free(copia);
	return (0);
}
*/
