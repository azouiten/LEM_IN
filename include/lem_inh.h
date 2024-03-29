/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_inh.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 22:40:08 by ohachim           #+#    #+#             */
/*   Updated: 2019/12/18 14:46:12 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_INH_H
# define LEM_INH_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <libft.h>

typedef	struct			s_agroups
{
	struct s_group		*group;
	int					score;
	int					n_vrtx;
	int					n_pths;
	struct s_agroups	*next;
}						t_agroups;

typedef	struct			s_group
{
	int					status;
	struct s_path		*path;
	int					load;
	int					size;
	struct s_group		*next;
}						t_group;

typedef	struct			s_v_buffer
{
	struct s_vertices	*vertex;
	struct s_v_buffer	*next;
}						t_v_buffer;

typedef	struct			s_path
{
	struct s_vertices	*vertex;
	int					status;
	struct s_edges		*edg;
	struct s_path		*next;
}						t_path;

typedef	struct			s_queue
{
	struct s_vertices	*item;
	int					access;
	struct s_vertices	*acc_ptr;
	struct s_queue		*last;
	struct s_path		*path;
	int					status;
	struct s_queue		*next;
}						t_queue;

typedef struct			s_input
{
	char				*line;
	struct s_input		*next;
}						t_input;

typedef struct			s_edges
{
	struct s_edges		*edge_end;
	struct s_vertices	*connection;
	int					flow;
	struct s_edges		*next;
}						t_edges;

typedef struct			s_vertices
{
	int					visited;
	int					flow;
	char				*name;
	int					hash;
	int					x;
	int					y;
	struct s_edges		*edges;
	struct s_vertices	*next;
}						t_vertices;

typedef struct			s_ants
{
	struct s_path		*path;
	int					in_end;
}						t_ants;

typedef struct			s_data
{
	int					ants;
	int					vertices;
	int					max_hash;
	struct s_v_buffer	*visited;
	struct s_vertices	**hash_table;
	struct s_vertices	*start;
	struct s_vertices	*end;
	struct s_input		*input_head;
	struct s_queue		*queue;
	struct s_queue		*free_q;
	struct s_path		*path;
	struct s_group		*groups;
	struct s_agroups	*agroups;
	struct s_ants		*moving_ant;
	struct s_group		**array_result;
	struct s_agroups	*result;
	int					c;
}						t_data;

int						ft_double_free(char **s1, char **s2);
int						ft_list_to_array(t_data *data, int gn);
int						ft_sort_result(t_data *data);
int						ft_qsort_group(t_data *data, int start, int end);
int						ft_free_data(t_data *data);
int						ft_create_data(t_data *data);
int						ft_error_input(char *line);
int						ft_create_hash(t_data *data);
int						ft_append_vertex(t_data *data, int hash,
		char *line, int vertex_position);
char					*ft_extract_name(char *line);
int						ft_hash_it(char *name, int vertices);
int						ft_create_edges(t_data *data);
int						ft_check_validity(t_data *data, char *name,
		char *connection);
char					*ft_extract_edge(char *line);
char					*ft_extract_connection(char *line);
void					ft_initialize_hdata(t_data *data);
void					ft_parse(t_data *data);
int						ft_get_input(t_data *data);
t_queue					*ft_add_queue(t_data *data, t_vertices
		**vertex, t_edges **edg, t_path **pth);
int						ft_print_moves(t_data *data, int ant_index,
		int arrived);
void					ft_unvisit(t_v_buffer *visited);
void					ft_exit(t_data *data);
void					ft_bfs(t_data *data);
void					ft_free_queue(t_data *data);
t_agroups				*ft_swing_paths(t_data *data, t_agroups *agroup);
int						ft_load_paths(t_data *data, t_group *group,
		int n_pths);
void					ft_add_flow(t_data *data);
void					ft_flush_vbuffer(t_data *data);
void					ft_add_path(t_data *data, t_vertices *vertex);
void					ft_add_to_path(t_data *data, t_group *group,
		t_vertices *vertex);
void					ft_collect_paths(t_data *data, t_edges *edges,
		t_group *group, int a);
void					ft_add_to_agroup(t_data *data);
int						ft_rescore(t_data *data, t_group *group);
void					ft_enhance_groups(t_data *data);
int						ft_biggest(t_data *data, t_group *group);
int						ft_count(t_data *data);
void					ft_calibrate_loads(t_data *data);
int						ft_rescore(t_data *data, t_group *group);
void					ft_free_agroups(t_data *data);

#endif
