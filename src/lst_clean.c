/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tylerlover911 <tylerlover911@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:46:45 by mkettab           #+#    #+#             */
/*   Updated: 2025/03/05 09:01:02 by tylerlover9      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	lst_clean(t_list **buf)
{
	t_list	*get_last;
	t_list	*clean_node;
	int		i;
	int		j;

	get_last = ft_getlast(*buf);
	i = 0;
	lst_clean_v2(get_last, buf, &i);
	if (!*buf)
		return ;
	clean_node = malloc(sizeof(t_list));
	if (!clean_node)
		return ;
	clean_node->next = NULL;
	clean_node->content = malloc(sizeof(char) * ((ft_strlen(get_last->content) - i) + 1));
	if (!(clean_node->content))
		return (free(clean_node));
	j = 0;
	while (get_last->content[i])
		clean_node->content[j++] = get_last->content[i++];
	clean_node->content[j] = 0;
	lst_free(*buf);
	*buf = clean_node;
}

void	lst_clean_v2(t_list *get_last, t_list **buf, int *i)
{
	if (!get_last || !get_last->content || !get_last->content[*i])
	{
		lst_free(*buf);
		*buf = NULL;
		return ;
	}		
	while (get_last->content[*i] && get_last->content[*i] != '\n')
		(*i)++;
	if (get_last->content[*i] == '\n')
		(*i)++;
	if (ft_strlen(get_last->content) - *i == 0)
	{
		lst_free(*buf);
		*buf = NULL;
		return ;
	}
}