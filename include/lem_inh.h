/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_inh.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 22:40:08 by ohachim           #+#    #+#             */
/*   Updated: 2019/11/10 17:33:51 by azouiten         ###   ########.fr       */
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
	struct s_path		*path;
	int					size;	// done
	int					nbr_id;	// done
	int					t_vrtx;	// the number of vertices this far!
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
	struct s_edges		*edg;
	struct s_path		*next;
}						t_path;

typedef	struct			s_queue
{
	struct s_vertices	*item;
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
	int					flow; // new;
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
	struct s_queue		*queue; // new
	struct s_queue		*free_q;// keeps the head of the q to be freed
	struct s_path		*path;	// result of the bfs !
	struct s_group		*groups;
	struct s_agroups	*agroups;
}						t_data;

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
						**vertex, t_edges **edg, t_path **pth); // new
void					ft_unvisit(t_v_buffer *visited);
// anas's stuff

void					ft_exit(t_data *data);
void					ft_bfs(t_data *data);
void					ft_free_queue(t_data *data);

#endif
