/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   review_list7.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 19:07:38 by sprotsen          #+#    #+#             */
/*   Updated: 2017/05/24 19:07:39 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_lem.h"

t_room	*find_struct_v3(char *name, t_room *tmp)
{
	while (tmp)
	{
		if (ft_strcmp(name, tmp->name) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	record_path_v3(t_room *line, t_room *list, t_tube *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		if (ft_strcmp(line->name, lst->name1) == 0)
			line->p[i++] = find_struct_v3(lst->name2, list);
		else if (ft_strcmp(line->name, lst->name2) == 0)
			line->p[i++] = find_struct_v3(lst->name1, list);
		lst = lst->next;
	}
}

t_room	*find_list(char *str, t_room *line)
{
	while (line)
	{
		if (ft_strcmp(str, line->name) == 0)
			return (line);
		line = line->next;
	}
	return (NULL);
}

void	find_path_to_end(t_room *list, t_room *line, t_tube *lst)
{
	int		i;
	t_room	*ptr;

	i = -1;
	while (lst)
	{
		if (ft_strcmp(line->name, lst->name1) == 0)
		{
			ptr = find_list(lst->name2, list);
			if (ptr->parent != NULL && ft_strcmp(ptr->parent, line->name) != 0)
				line->p[++i] = ptr;
		}
		else if (ft_strcmp(line->name, lst->name2) == 0)
		{
			ptr = find_list(lst->name1, list);
			if (ptr->parent != NULL && ft_strcmp(ptr->parent, line->name) != 0)
				line->p[++i] = ptr;
		}
		lst = lst->next;
	}
}

t_algo	*create_copy(t_room *ptr)
{
	t_algo	*lst;

	lst = (t_algo*)malloc(sizeof(t_algo));
	lst->name = ft_strdup(ptr->name);
	lst->len = ptr->len;
	lst->next = NULL;
	return (lst);
}
