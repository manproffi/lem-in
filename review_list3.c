/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   review_list3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 19:03:21 by sprotsen          #+#    #+#             */
/*   Updated: 2017/05/24 19:03:23 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_lem.h"

void	find_tubes(t_list *tmp)
{
	char	*str;

	while (tmp)
	{
		if (tmp->content_size == 0)
		{
			if ((str = ft_strchr(tmp->content, '-')) != NULL)
			{
				find_shtrix_in_content(tmp->content);
				if (ft_strlen(str + 1) == 0 || str - (char*)tmp->content == 0)
					exit(write(2, "ERROR: room's name include '-'\n", 31));
				tmp->content_size = 3000000002;
			}
		}
		tmp = tmp->next;
	}
}

void	review_correct_order(t_list *tmp)
{
	size_t	a;

	a = 3000000001;
	while (tmp)
	{
		if (tmp->content_size > 3000000000 && tmp->content_size < 3000000003)
		{
			if (a < tmp->content_size)
				a = tmp->content_size;
			if (a > tmp->content_size)
				exit(write(2, "ERROR\n", 6));
		}
		tmp = tmp->next;
	}
}

void	review_start_end(t_list *lst)
{
	int		count[4];

	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	count[3] = 0;
	while (lst)
	{
		if (lst->content_size == 3330000001)
			count[0] += 1;
		else if (lst->content_size == 3100000000)
			count[1] += 1;
		else if (lst->content_size == 3330000002)
			count[2] += 1;
		else if (lst->content_size == 3200000000)
			count[3] += 1;
		lst = lst->next;
	}
	if (count[0] != 1 || count[1] != 1 || count[2] != 1 || count[3] != 1)
		exit(write(2, "ERROR\n", 6));
}

void	ft_lstadd_room(t_room **alst, t_room *new)
{
	new->next = (*alst);
	(*alst) = new;
}

t_room	*review_room(t_list *lst)
{
	t_list	*tmp;
	t_room	*list;
	t_room	*copy;
	char	**mass;

	tmp = lst;
	list = NULL;
	while (tmp)
	{
		if (tmp->content_size == 3000000001 || tmp->content_size == 3100000000
			|| tmp->content_size == 3200000000)
		{
			mass = ft_strsplit(tmp->content, ' ');
			copy = (t_room*)malloc(sizeof(t_room));
			copy->name = ft_strdup(mass[0]);
			copy->x = ft_atoi(mass[1]);
			copy->y = ft_atoi(mass[2]);
			copy->content_size = tmp->content_size;
			ft_lstadd_room(&list, copy);
			ft_strdel_char_mass(mass);
		}
		tmp = tmp->next;
	}
	return (list);
}
