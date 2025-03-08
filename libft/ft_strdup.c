/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuesta- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:57:36 by mcuesta-          #+#    #+#             */
/*   Updated: 2024/10/02 11:52:19 by mcuesta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char		*str;
	size_t		length;

	length = ft_strlen(s) + 1;
	str = (char *) malloc(length * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s, length);
	return (str);
}

/*
#include <stdio.h>
int main() {
    const char* original = "Hola, Mundo!";
    char* copia = ft_strdup(original, 10);
    if (copia == NULL) {
        printf("Error: No se pudo duplicar la cadena.\n");
        return 1;
    }
    printf("Cadena original: %s\n", original);
    printf("Cadena duplicada: %s\n", copia);
    
    free(copia);
    
    return 0;
}
*/
