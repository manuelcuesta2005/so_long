/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuesta- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 20:27:26 by mcuesta-          #+#    #+#             */
/*   Updated: 2025/03/01 20:27:27 by mcuesta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_index(int n, int *array)
{
	int	i;

	i = 0;
	while (array[i] != n)
		i++;
	return (i);
}
