/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   review_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 19:47:36 by sprotsen          #+#    #+#             */
/*   Updated: 2017/04/13 19:47:38 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_lem.h"

t_room	*find_end(t_room *lst)
{
	while (lst)
	{
		if (lst->content_size == 3200000000)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

void	algorithm(t_tube *lst, t_room *tmp, t_list *total)
{
	t_room		*copy;
	t_room		*list;

	copy = tmp;
	while (copy)
	{
		if (copy->content_size == 3200000000)
		{
			list = copy;
			copy->parent = ft_strdup("end");
			copy->len = 0;
		}
		else
			copy->len = -1;
		copy = copy->next;
	}
	list->child = find_n_child(list, lst);
	if (list->child == 0)
		exit(write(2, "ERROR: not enough path\n", 23));
	list->p = (t_room**)malloc(sizeof(t_room*) * list->child);
	record_path(list, lst, tmp);
	next_fun_algorithm(tmp, lst, total);
}

void	review_tubes_dup(t_tube *lst)
{
	t_tube	*ptr;

	while (lst->next)
	{
		ptr = lst->next;
		while (ptr)
		{
			if (ft_strcmp(lst->name1, ptr->name1) == 0 &&
				ft_strcmp(lst->name2, ptr->name2) == 0)
			{
				ft_printf("%s %s\n", lst->name1, lst->name2);
				ft_printf("%s %s\n", ptr->name1, ptr->name2);
				exit(write(2, "ERROR: duplicate links\n", 23));
			}
			if (ft_strcmp(lst->name1, ptr->name2) == 0 &&
				ft_strcmp(lst->name2, ptr->name1) == 0)
			{
				ft_printf("%s %s\n", lst->name1, lst->name2);
				ft_printf("%s %s\n", ptr->name1, ptr->name2);
				exit(write(2, "ERROR: duplicate links\n", 23));
			}
			ptr = ptr->next;
		}
		lst = lst->next;
	}
}

void	fun_next_1(t_list **list)
{
	t_room	*lst;
	t_tube	*tube;

	find_comment((*list)->next);
	find_start_end((*list)->next);
	find_room((*list)->next);
	find_tubes((*list)->next);
	review_correct_order((*list)->next);
	review_start_end((*list)->next);
	lst = review_room((*list)->next);
	review_duplicate_room(lst);
	review_duplicate_n_ants((*list)->next);
	tube = write_tube((*list)->next);
	if (tube == NULL)
		exit(write(2, "ERROR: no links\n", 16));
	review_tubes(tube, lst);
	review_tubes_dup(tube);
	algorithm(tube, lst, *list);
	del_list_room(&lst);
	del_list_tube(&tube);
}
