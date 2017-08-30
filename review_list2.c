/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   review_list2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 19:01:32 by sprotsen          #+#    #+#             */
/*   Updated: 2017/05/24 19:01:36 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_lem.h"

void	find_comment(t_list *tmp)
{
	char	*str;

	while (tmp)
	{
		str = tmp->content;
		if (str[0] == '#' && str[1] != '#')
			tmp->content_size = 3000000011;
		tmp = tmp->next;
	}
}

void	find_start_end_part(char **mass, char *str, t_list *tmp)
{
	int		len;

	len = 0;
	while (mass[len] != '\0')
		len++;
	if (len == 3)
		validation_int(mass);
	else
		exit(write(2, "ERROR\n", 6));
	if (ft_strequ(str, "##start") == 1)
	{
		tmp->content_size = 3330000001;
		tmp->next->content_size = 3100000000;
	}
	else if (ft_strequ(str, "##end") == 1)
	{
		tmp->content_size = 3330000002;
		tmp->next->content_size = 3200000000;
	}
}

void	find_start_end(t_list *tmp)
{
	char	*str;
	char	**mass;

	while (tmp)
	{
		str = tmp->content;
		if (str[0] == '#' && str[1] == '#')
		{
			if (ft_strequ(str, "##start") == 1 || ft_strequ(str, "##end") == 1)
			{
				if (tmp->next == NULL)
					exit(write(2, "ERROR\n", 6));
				mass = ft_strsplit(tmp->next->content, ' ');
				find_start_end_part(mass, str, tmp);
				ft_strdel_char_mass(mass);
			}
			else
				tmp->content_size = 3330000000;
		}
		tmp = tmp->next;
	}
}

void	find_room(t_list *tmp)
{
	char	**mass;
	int		len;

	while (tmp)
	{
		if (tmp->content_size == 0)
		{
			mass = ft_strsplit(tmp->content, ' ');
			len = 0;
			while (mass[len] != '\0')
				len++;
			if (len == 3)
			{
				validation_int(mass);
				tmp->content_size = 3000000001;
			}
			ft_strdel_char_mass(mass);
		}
		tmp = tmp->next;
	}
}

void	find_shtrix_in_content(char *str)
{
	int		i;

	i = 0;
	while (*str)
	{
		if (*str == '-')
			i++;
		str++;
	}
	if (i > 1)
	{
		exit(write(2, "ERROR: room's name include '-' character\n", 41));
	}
}
