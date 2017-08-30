/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   review_list5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 19:05:35 by sprotsen          #+#    #+#             */
/*   Updated: 2017/05/24 19:05:37 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_lem.h"

int		find_n_child(t_room *list, t_tube *lst)
{
	int		n;

	n = 0;
	while (lst)
	{
		if (ft_strcmp(list->name, lst->name1) == 0)
			n++;
		else if (ft_strcmp(list->name, lst->name2) == 0)
			n++;
		lst = lst->next;
	}
	return (n);
}

t_room	*find_struct(char *name, t_room *tmp)
{
	while (tmp)
	{
		if (ft_strcmp(name, tmp->name) == 0 && tmp->len == -1)
		{
			tmp->len = 1;
			tmp->parent = ft_strdup(name);
			return (tmp);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

void	record_path(t_room *list, t_tube *lst, t_room *tmp)
{
	int		i;

	i = 0;
	while (lst)
	{
		if (ft_strcmp(list->name, lst->name1) == 0)
		{
			list->p[i] = find_struct(lst->name2, tmp);
			list->p[i]->p_parent = list;
			i++;
		}
		else if (ft_strcmp(list->name, lst->name2) == 0)
		{
			list->p[i] = find_struct(lst->name1, tmp);
			list->p[i]->p_parent = list;
			i++;
		}
		lst = lst->next;
	}
}

t_room	*find_struct_v2(char *name, t_room *tmp, int k)
{
	while (tmp)
	{
		if (ft_strcmp(name, tmp->name) == 0 && tmp->len == -1)
		{
			tmp->len = k + 1;
			tmp->parent = ft_strdup(name);
			return (tmp);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

void	record_path_v2_part1_3(int k, t_room *list, t_tube *lst, t_room *tmp)
{
	while (--k >= 0)
	{
		list->p[k]->p_parent = NULL;
		list->p[k]->len = -1;
	}
	list->p[0] = find_struct_v2(lst->name1, tmp, list->len);
}
