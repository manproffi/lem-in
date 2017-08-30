/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   review_list4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 19:04:35 by sprotsen          #+#    #+#             */
/*   Updated: 2017/05/24 19:04:37 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_lem.h"

void	review_duplicate_room(t_room *lst)
{
	t_room	*tmp;

	while (lst->next != NULL)
	{
		tmp = lst->next;
		while (tmp)
		{
			if (ft_strcmp(lst->name, tmp->name) == 0)
				exit(write(2, "ERROR: duplicate name\n", 22));
			else if (lst->x == tmp->x && lst->y == tmp->y)
				exit(write(2, "ERROR: duplicate coordinate\n", 28));
			tmp = tmp->next;
		}
		lst = lst->next;
	}
}

void	review_duplicate_n_ants(t_list *lst)
{
	while (lst)
	{
		if (lst->content_size == 0)
			exit(write(2, "ERROR: duplicate n ants\n", 24));
		lst = lst->next;
	}
}

void	ft_lstadd_tube(t_tube **alst, t_tube *new)
{
	new->next = (*alst);
	(*alst) = new;
}

t_tube	*write_tube(t_list *lst)
{
	t_tube	*tmp;
	t_tube	*copy;
	char	*str;
	int		len;

	tmp = NULL;
	while (lst)
	{
		if (lst->content_size == 3000000002)
		{
			str = ft_strchr(lst->content, '-');
			len = str - (char*)lst->content;
			copy = (t_tube*)malloc(sizeof(t_tube));
			copy->name1 = ft_strnew(len);
			copy->name1 = ft_strncpy(copy->name1, lst->content, len);
			copy->name2 = ft_strdup(((char*)lst->content) + len + 1);
			copy->flag = 0;
			ft_lstadd_tube(&tmp, copy);
		}
		lst = lst->next;
	}
	return (tmp);
}

void	review_tubes(t_tube *lst, t_room *tmp)
{
	int		dupl1;
	int		dupl2;
	t_room	*list;

	while (lst)
	{
		dupl1 = 0;
		dupl2 = 0;
		if (ft_strcmp(lst->name1, lst->name2) == 0)
			exit(write(2, "ERROR: for tube - n1 and to n2 are equal\n", 41));
		list = tmp;
		while (list)
		{
			if (ft_strcmp(list->name, lst->name1) == 0)
				dupl1 += 1;
			else if (ft_strcmp(list->name, lst->name2) == 0)
				dupl2 += 1;
			list = list->next;
		}
		if (dupl1 == 0 || dupl2 == 0)
			exit(write(2, "ERROR: room's name isn't available for path\n", 44));
		lst = lst->next;
	}
}
