/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head_lem.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 20:13:29 by sprotsen          #+#    #+#             */
/*   Updated: 2017/04/05 20:13:30 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_LEM_H
# define HEAD_LEM_H

# include "libft/libft.h"
# include "ft_printf/printhead.h"
# include <unistd.h>
# include <fcntl.h>

# define FTI ft_isdigit

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	size_t			content_size;
	int				len;
	int				child;
	char			*parent;
	struct s_room	*p_parent;
	struct s_room	**p;
	struct s_room	*next;
}					t_room;

typedef struct		s_tube
{
	char			*name1;
	char			*name2;
	int				flag;
	struct s_tube	*next;
}					t_tube;

typedef struct		s_algo
{
	char			*name;
	int				len;
	int				index;
	struct s_algo	*next;
}					t_algo;

void				fun_next_1(t_list **list);
void				validation_int(char **mass);
void				add_len_for_start(t_algo **mass, int n_path, int n_ants, \
	t_list *total);
void				del_list_list(t_list **list);
void				del_list_room(t_room **list);
void				del_list_tube(t_tube **list);
void				del_list_algo(t_algo **list);
int					review_on_digit(char **mass);
void				validation_1(t_list **list);
void				validation_int(char **mass);
void				find_comment(t_list *tmp);
void				find_start_end_part(char **mass, char *str, t_list *tmp);
void				find_start_end(t_list *tmp);
void				find_room(t_list *tmp);
void				find_shtrix_in_content(char *str);
void				find_tubes(t_list *tmp);
void				review_correct_order(t_list *tmp);
void				review_start_end(t_list *lst);
void				ft_lstadd_room(t_room **alst, t_room *new);
t_room				*review_room(t_list *lst);
void				review_duplicate_room(t_room *lst);
void				review_duplicate_n_ants(t_list *lst);
void				ft_lstadd_tube(t_tube **alst, t_tube *new);
t_tube				*write_tube(t_list *lst);
void				review_tubes(t_tube *lst, t_room *tmp);
int					find_n_child(t_room *list, t_tube *lst);
t_room				*find_struct(char *name, t_room *tmp);
void				record_path(t_room *list, t_tube *lst, t_room *tmp);
t_room				*find_struct_v2(char *name, t_room *tmp, int k);
void				record_path_v2_part1_3(int k, t_room *list, t_tube *lst, \
	t_room *tmp);
void				record_path_v2_part1_2(int k, t_room *list, t_tube *lst, \
	t_room *tmp);
void				record_path_v2(t_room *list, t_tube *lst, t_room *tmp, \
	char *str_name);
void				find_next_path(int i, t_room *list_start, t_tube *lst, \
	char *str_name);
t_room				*find_start(t_room *lst);
t_room				*find_end(t_room *lst);
t_room				*find_struct_v3(char *name, t_room *tmp);
void				record_path_v3(t_room *line, t_room *list, t_tube *lst);
t_room				*find_list(char *str, t_room *line);
void				find_path_to_end(t_room *list, t_room *line, t_tube *lst);
t_algo				*create_copy(t_room *ptr);
void				ft_lstadd_algo(t_algo **alst, t_algo *new);
int					find_ants(t_list *lst);
void				create_paths_part(t_room *line, t_algo **mass);
void				create_paths(t_room *line, t_list *total);
void				next_fun_algorithm(t_room *list, t_tube *lst, \
	t_list *total);
void				print_result(t_algo **mass, int n_path, int n_ants, \
	int row[3][n_path]);
void				bonus_print(t_algo **mass, int n_path, int row[3][n_path]);
int					ft_lstsize_v1(t_algo *begin_list);
int					find_min(int n_path, int row[3][n_path]);
int					calculate_sum(int n_path, int row[3][n_path]);
int					sum_ants_in_end(t_algo **mass, int n_path, \
	int row[3][n_path]);
void				print_result_part(t_algo *lst, int *ind);
void				assignment(t_algo **mass, int n_path, int n_ants, \
	int row[3][n_path]);

#endif
