/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 20:03:53 by sprotsen          #+#    #+#             */
/*   Updated: 2017/04/05 20:03:55 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_lem.h"

void	new_fun_valid(char **mass, int i)
{
	if (i == 3 && ft_isdigit(mass[1][0]) == 1 && ft_isdigit(mass[2][0]) == 1)
	{
		if ((mass[0][0] == 'L' || mass[0][0] == '#') && mass[0][1] != '#')
			exit(write(2, "ERROR\n", 6));
	}
}

int		validatino_read(char *line, int i)
{
	char	**mass;

	mass = ft_strsplit(line, ' ');
	while (mass[i] != '\0')
		i++;
	if (mass[0][0] == '#' || (i == 1 && ft_strchr(line, '-') != NULL))
		new_fun_valid(mass, i);
	else if (i == 1 && ft_strchr(line, '-') == NULL)
	{
		if (review_on_digit(mass) == -1)
			return (-1);
	}
	else if (i == 3)
		validation_int(mass);
	else
	{
		ft_strdel_char_mass(mass);
		return (-1);
	}
	ft_strdel_char_mass(mass);
	return (1);
}

t_list	*read_from_file(char **argv, t_list *list)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit(write(2, "ERROR\n", 6));
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] == 0)
		{
			ft_strdel(&line);
			break ;
		}
		if (validatino_read(line, 0) == -1)
		{
			ft_strdel(&line);
			break ;
		}
		ft_lstaddend(&list, ft_lstnew((void*)line, ft_strlen(line) + 1));
		ft_strdel(&line);
	}
	close(fd);
	return (list);
}

t_list	*read_screen(t_list *list)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (line[0] == 0)
		{
			ft_strdel(&line);
			break ;
		}
		if (validatino_read(line, 0) == -1)
			break ;
		ft_lstaddend(&list, ft_lstnew((void*)line, ft_strlen(line) + 1));
		ft_strdel(&line);
	}
	return (list);
}

int		main(int argc, char **argv)
{
	t_list		*list;
	t_list		*tmp;

	list = ft_lstnew(NULL, 0);
	if (argc == 2)
		read_from_file(argv, list);
	else if (argc > 2)
		exit(write(2, "ERROR\n", 6));
	else
		read_screen(list);
	tmp = list;
	tmp->next == NULL ? exit(write(2, "ERROR\n", 6)) : 0;
	tmp->next->content == NULL ? exit(write(2, "ERROR\n", 6)) : 0;
	if (ft_lstsize(tmp) < 7)
		exit(write(2, "ERROR\n", 6));
	while (tmp)
	{
		tmp->content_size = 0;
		tmp = tmp->next;
	}
	validation_1(&list);
	fun_next_1(&list);
	del_list_list(&list);
	return (0);
}
