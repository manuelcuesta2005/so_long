/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuesta- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:05:09 by mcuesta-          #+#    #+#             */
/*   Updated: 2024/10/02 12:05:53 by mcuesta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	char	cast;

	cast = c;
	if (cast >= 65 && cast <= 90)
		cast = cast + 32;
	else
		return (c);
	return (cast);
}

/*
#include <stdio.h>
int main()
{
    printf("%c \n", ft_tolower('A'));
    printf("%c \n", ft_tolower('B'));
    printf("%c \n", ft_tolower('C'));
    printf("%c \n", ft_tolower('D'));
}
*/
