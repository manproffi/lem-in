/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 18:59:14 by sprotsen          #+#    #+#             */
/*   Updated: 2017/05/24 18:59:15 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_lem.h"

void	validation_int(char **mass)
{
	long long	a;
	int			i;

	a = 0;
	i = -1;
	if (mass[0][0] == 'L' || mass[0][0] == '#')
		exit(write(2, "ERROR: L or # in the first place in room's name\n", 48));
	while ((mass[1][++i]))
		if ((ft_isdigit(mass[1][i]) == 0 && mass[1][0] != '-'))
			exit(write(2, "ERROR\n", 6));
	i = -1;
	while ((mass[2][++i]))
		if ((ft_isdigit(mass[2][i]) == 0 && mass[2][0] != '-'))
			exit(write(2, "ERROR\n", 6));
	if (ft_strlen(mass[1]) > 10 || (mass[1][0] == '-' && FTI(mass[1][1]) == 0))
		exit(write(2, "ERROR\n", 6));
	a = ft_atoi_ulli(mass[1]);
	if (a > 2147483647 || a < -2147483648)
		exit(write(2, "ERROR\n", 6));
	if (ft_strlen(mass[2]) > 10 || (mass[2][0] == '-' && FTI(mass[2][1]) == 0))
		exit(write(2, "ERROR\n", 6));
	a = ft_atoi_ulli(mass[2]);
	if (a > 2147483647 || a < -2147483648)
		exit(write(2, "ERROR\n", 6));
}

void	validation_1(t_list **list)
{
	t_list		*tmp;
	long long	a;
	int			i;
	char		*str;

	tmp = (*list)->next;
	i = -1;
	while (ft_strnequ(tmp->content, "#", 1) == 1)
	{
		if (ft_strnequ(tmp->content, "##", 2) == 1)
			exit(write(2, "ERROR\n", 6));
		tmp->content_size = 3000000000;
		tmp = tmp->next;
	}
	if (ft_strlen(tmp->content) > 10)
		exit(write(2, "ERROR\n", 6));
	str = tmp->content;
	while (str[++i])
		if (ft_isdigit(str[i]) == 0)
			exit(write(2, "ERROR\n", 6));
	a = ft_atoi_ulli(tmp->content);
	if (a > 2147483647 || a < 1)
		exit(write(2, "ERROR\n", 6));
	tmp->content_size = (size_t)a;
}

int		review_on_digit(char **mass)
{
	int		j;

	j = -1;
	while (mass[0][++j])
		if (ft_isdigit(mass[0][j]) == 0)
		{
			ft_strdel_char_mass(mass);
			return (-1);
		}
	return (1);
}
