/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_path2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 19:14:19 by sprotsen          #+#    #+#             */
/*   Updated: 2017/05/24 19:14:21 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_lem.h"

void	print_result(t_algo **mass, int n_path, int n_ants, int row[3][n_path])
{
	int		k;
	int		ind;
	t_algo	*lst;

	k = -1;
	ind = 1;
	while (sum_ants_in_end(mass, n_path, row) != n_ants)
	{
		k = -1;
		while (++k < n_path)
		{
			if (row[0][k] != 2147483647)
			{
				lst = mass[k];
				while (lst->next)
				{
					print_result_part(lst, &ind);
					lst = lst->next;
				}
			}
		}
		ft_printf("\n"RESET);
	}
}

void	bonus_print(t_algo **mass, int n_path, int row[3][n_path])
{
	int			k;
	t_algo		*lst;

	k = -1;
	ft_printf(RED"\n\nAnts walked on the next ways:\n"RESET);
	while (++k < n_path)
	{
		if (row[0][k] != 2147483647)
		{
			lst = mass[k];
			while (lst)
			{
				ft_printf(GREEN"%s ", lst->name);
				lst = lst->next;
			}
			ft_printf("\n");
		}
	}
}

void	assignment(t_algo **mass, int n_path, int n_ants, int row[3][n_path])
{
	int		k;
	t_algo	*lst;

	k = -1;
	while (++k < n_path)
	{
		if (row[0][k] != 2147483647)
		{
			lst = mass[k];
			while (lst->next)
			{
				lst->len = 0;
				lst = lst->next;
			}
			lst->len = row[1][k];
		}
	}
	print_result(mass, n_path, n_ants, row);
	bonus_print(mass, n_path, row);
}
