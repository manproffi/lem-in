/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 20:31:01 by sprotsen          #+#    #+#             */
/*   Updated: 2017/05/16 20:31:04 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_lem.h"

void	del_list_algo(t_algo **list)
{
	if (*list)
	{
		del_list_algo(&(*list)->next);
		ft_strdel(&(*list)->name);
		free(*list);
	}
}

void	del_list_list(t_list **list)
{
	if (*list)
	{
		del_list_list(&(*list)->next);
		ft_memdel(&(*list)->content);
		free(*list);
	}
}

void	del_list_room(t_room **list)
{
	if (*list)
	{
		del_list_room(&(*list)->next);
		if ((*list)->parent != NULL)
			ft_strdel(&(*list)->parent);
		if ((*list)->child > 0)
			free((*list)->p);
		ft_strdel(&(*list)->name);
		free(*list);
	}
}

void	del_list_tube(t_tube **list)
{
	if (*list)
	{
		del_list_tube(&(*list)->next);
		ft_strdel(&(*list)->name1);
		ft_strdel(&(*list)->name2);
		free(*list);
	}
}
