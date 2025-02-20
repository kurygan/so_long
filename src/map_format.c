/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkettab <mkettab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 00:18:50 by mkettab           #+#    #+#             */
/*   Updated: 2025/02/20 02:44:39 by mkettab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_strrcmp(char *s1, char *s2)
{
	int	len_s1;
	int	len_s2;
	
	len_s1 = ft_strlen(s1) - 1;
	len_s2 = ft_strlen(s2) - 1;

	while (s1[len_s1] && s2[len_s2] && s1[len_s1] == s2[len_s2])
	{
		len_s1--;
		len_s2--;
	}
	return (s1[len_s1] - s2[len_s2]);
}

bool	verify_format(char *str)
{
	printf("%d\n", ft_strrcmp(str, ".ber"));
	if (!str || ft_strrcmp(str, ".ber") != 0)
		return (false);
	return (true);
}