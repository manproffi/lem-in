/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 13:11:42 by sprotsen          #+#    #+#             */
/*   Updated: 2017/05/07 13:11:46 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_lem.h"

void	calc_ants_on_path(t_algo **mass, int n_path, int n_ants, int a[n_path])
{
	int		row[4][n_path];
	int		j;
	int		k;

	k = -1;
	while (++k < n_path)
	{
		row[0][k] = ft_lstsize_v1(mass[k]) - 1;
		if (row[0][k] == 0 || a[k] == -1)
			row[0][k] = 2147483647;
		row[1][k] = 0;
		row[2][k] = row[0][k] + row[1][k];
		row[3][k] = 0;
	}
	while (calculate_sum(n_path, row) != n_ants)
	{
		j = find_min(n_path, row);
		row[1][j] += 1;
		row[2][j] = row[0][j] + row[1][j];
	}
	assignment(mass, n_path, n_ants, row);
}

void	print_first_part(t_list *total)
{
	while (total)
	{
		ft_printf(GREEN"%s\n", total->content);
		total = total->next;
	}
	ft_printf("\n\n"RESET);
}

void	add_part1(t_algo **mass, int n_path, int a[n_path], int ind[2])
{
	if (ft_lstsize_v1(mass[ind[0]]->next) >= ft_lstsize_v1(mass[ind[1]]->next))
		a[ind[0]] = -1;
	else
		a[ind[1]] = -1;
}

void	add_len_for_start1(t_algo **mass, int n_path, int a[n_path], int ind[2])
{
	t_algo	*ptr;
	t_algo	*ptr1;

	while (++ind[0] < n_path - 1)
	{
		ptr = mass[ind[0]]->next;
		if (ptr && a[ind[0]] != -1)
			while (ptr->next)
			{
				ind[1] = ind[0];
				while (++ind[1] < n_path)
				{
					ptr1 = mass[ind[1]]->next;
					while (ptr1 && (ptr1->next))
					{
						if (ft_strcmp(ptr->name, ptr1->name) == 0)
							add_part1(mass, n_path, a, ind);
						ptr1 = ptr1->next;
					}
				}
				ptr = ptr->next;
			}
	}
}

void	add_len_for_start(t_algo **mass, int n_path, int n_ants, t_list *total)
{
	int		a[n_path];
	int		j;
	int		ind[2];

	ind[0] = -1;
	ind[1] = -1;
	j = -1;
	while (++j < n_path)
		a[j] = 0;
	add_len_for_start1(mass, n_path, a, ind);
	print_first_part(total->next);
	calc_ants_on_path(mass, n_path, n_ants, a);
}
