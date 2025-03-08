/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuesta- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:50:03 by mcuesta-          #+#    #+#             */
/*   Updated: 2024/10/02 11:20:22 by mcuesta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	char	*string;
	size_t	i;

	string = (char *)s;
	i = 0;
	while (i < n)
	{
		string[i] = '\0';
		i++;
	}
}

/*
#include <stdio.h>
int main()
{
    char *string[256];
    ft_bzero(string, 8);
    printf("%s", *string);
}
*/
