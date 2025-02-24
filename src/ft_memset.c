/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:25:29 by mkettab           #+#    #+#             */
/*   Updated: 2024/10/18 21:47:23 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*char_ptr;
	size_t			i;

	char_ptr = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		char_ptr[i] = c;
		i++;
	}
	return (char_ptr);
}
