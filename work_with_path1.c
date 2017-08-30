/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_path1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 19:13:18 by sprotsen          #+#    #+#             */
/*   Updated: 2017/05/24 19:13:20 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head_lem.h"

int		ft_lstsize_v1(t_algo *begin_list)
{
	int		count;
	t_algo	*list;

	count = 0;
	list = begin_list;
	if (list)
	{
		while (list)
		{
			count++;
			list = list->next;
		}
		return (count);
	}
	else
		return (0);
}

int		find_min(int n_path, int row[3][n_path])
{
	int		i;
	int		min;
	int		index;

	i = -1;
	min = row[2][0];
	index = 0;
	while (++i < n_path)
	{
		if (min == row[2][i])
		{
			if (row[0][index] < row[2][i])
				min = row[2][i];
			index = i;
		}
		else if (min > row[2][i])
		{
			min = row[2][i];
			index = i;
		}
	}
	return (index);
}

int		calculate_sum(int n_path, int row[3][n_path])
{
	int		i;
	int		sum;

	sum = 0;
	i = -1;
	while (++i < n_path)
		sum += row[1][i];
	return (sum);
}

int		sum_ants_in_end(t_algo **mass, int n_path, int row[3][n_path])
{
	int		res;
	int		k;

	res = 0;
	k = -1;
	while (++k < n_path)
	{
		if (row[0][k] != 2147483647)
			res += mass[k]->len;
	}
	return (res);
}

void	print_result_part(t_algo *lst, int *ind)
{
	if (lst->next->len > 0)
	{
		if (!lst->next->next)
		{
			lst->index = *ind;
			*ind += 1;
		}
		else
			lst->index = lst->next->index;
		ft_printf(YELLOW"L%d-%s ", lst->index, lst->name);
		lst->len += 1;
		lst->next->len -= 1;
	}
}
