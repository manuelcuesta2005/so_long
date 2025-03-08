/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuesta- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:52:57 by mcuesta-          #+#    #+#             */
/*   Updated: 2024/10/02 12:07:01 by mcuesta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	char	cast;

	cast = c;
	if (cast >= 97 && cast <= 122)
		cast = cast - 32;
	else
		return (c);
	return (cast);
}

/*
#include <stdio.h>
int main()
{
    printf("%c \n", ft_toupper('a'));
    printf("%c \n", ft_toupper('b'));
    printf("%c \n", ft_toupper('c'));
    printf("%c \n", ft_toupper('d'));
}
*/
