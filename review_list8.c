/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   review_list8.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 19:08:16 by sprotsen          #+#    #+#             */
/*   Updated: 2017/05/24 19:08:17 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_lem.h"

void	ft_lstadd_algo(t_algo **alst, t_algo *new)
{
	new->next = (*alst);
	(*alst) = new;
}

int		find_ants(t_list *lst)
{
	while (lst)
	{
		if (lst->content_size < 3000000000 && lst->content_size > 0)
			return (lst->content_size);
		lst = lst->next;
	}
	return (0);
}

void	create_paths_part(t_room *line, t_algo **mass)
{
	int		i;
	t_room	*ptr;

	i = -1;
	while (++i < line->child)
	{
		ptr = line->p[i];
		if (ptr == NULL)
		{
			if (line->child == 1)
				exit(write(2, "ERROR: not enough path\n", 23));
		}
		else if (ptr->len > -1)
		{
			while (ptr)
			{
				ft_lstadd_algo(&mass[i], create_copy(ptr));
				ptr = ptr->p_parent;
			}
		}
	}
}

void	create_paths(t_room *line, t_list *total)
{
	int		i;
	t_algo	**mass;

	mass = (t_algo**)malloc(sizeof(t_algo*) * line->child);
	i = -1;
	while (++i < line->child)
	{
		mass[i] = (t_algo*)malloc(sizeof(t_algo));
		mass[i]->name = ft_strdup(line->name);
	}
	create_paths_part(line, mass);
	add_len_for_start(mass, line->child, find_ants(total), total);
	i = -1;
	while (++i < line->child)
		del_list_algo(&mass[i]);
	free(mass);
}

void	next_fun_algorithm(t_room *list, t_tube *lst, t_list *total)
{
	t_room	*start;
	t_room	*end;
	t_room	*line;
	int		i;

	i = 0;
	start = find_start(list);
	end = find_end(list);
	while (++i < 100)
		find_next_path(i, list, lst, start->name);
	if (start->parent == NULL)
		exit(write(2, "ERROR: not enough path\n", 23));
	line = (t_room*)malloc(sizeof(t_room));
	line->name = ft_strdup(start->name);
	line->child = find_n_child(start, lst);
	if (line->child == 0)
		exit(write(2, "ERROR\n", 6));
	line->p = (t_room**)malloc(sizeof(t_room*) * line->child);
	find_path_to_end(list, line, lst);
	create_paths(line, total);
	free(line->name);
	free(line->p);
	free(line);
}
