/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   review_list6.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 19:06:21 by sprotsen          #+#    #+#             */
/*   Updated: 2017/05/24 19:06:23 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_lem.h"

void	record_path_v2_part1_2(int k, t_room *list, t_tube *lst, t_room *tmp)
{
	while (--k >= 0)
	{
		list->p[k]->p_parent = NULL;
		list->p[k]->len = -1;
	}
	list->p[0] = find_struct_v2(lst->name2, tmp, list->len);
}

void	record_path_v2(t_room *list, t_tube *lst, t_room *tmp, char *str_name)
{
	int		i;

	i = 0;
	while (lst)
	{
		if (ft_strcmp(list->name, lst->name1) == 0 &&
			ft_strcmp(list->parent, lst->name2) != 0)
		{
			if (ft_strcmp(str_name, lst->name2) == 0)
				return (record_path_v2_part1_2(i, list, lst, tmp));
			list->p[i] = find_struct_v2(lst->name2, tmp, list->len);
			if (list->p[i] != NULL)
				list->p[i++]->p_parent = list;
		}
		else if (ft_strcmp(list->name, lst->name2) == 0 &&
			ft_strcmp(list->parent, lst->name1) != 0)
		{
			if (ft_strcmp(str_name, lst->name1) == 0)
				return (record_path_v2_part1_3(i, list, lst, tmp));
			list->p[i] = find_struct_v2(lst->name1, tmp, list->len);
			if (list->p[i] != NULL)
				list->p[i++]->p_parent = list;
		}
		lst = lst->next;
	}
}

void	find_next_path(int i, t_room *list_start, t_tube *lst, char *str_name)
{
	t_room	*list;

	list = list_start;
	while (list)
	{
		if (list->len == i && list->content_size != 3100000000)
		{
			list->child = find_n_child(list, lst) - 1;
			if (list->child > 0)
			{
				list->p = (t_room**)malloc(sizeof(t_room*) * list->child);
				record_path_v2(list, lst, list_start, str_name);
			}
		}
		list = list->next;
	}
}

t_room	*find_start(t_room *lst)
{
	while (lst)
	{
		if (lst->content_size == 3100000000)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
