/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_inh.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 22:40:08 by ohachim           #+#    #+#             */
/*   Updated: 2019/10/11 19:10:34 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_INH_H
# define LEM_INH_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <libft.h>

typedef	struct			s_v_buffer
{
	struct s_vertices	*vertex;
	struct s_v_buffer	*next;
}						t_v_buffer;

typedef	struct			s_queue // new
{
	struct s_vertices	*item;
	struct s_queue		*last;
	char				*path;
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
	int					status;
	struct s_vertices	*connection;
	int					flow; // new;
	struct s_edges		*next;
}						t_edges;

typedef struct			s_vertices
{
	int					visited;
	int					status;
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
					**vertex, char *path); // new
void					ft_unvisit(t_v_buffer *visited);
// anas's stuff

void					ft_exit(t_data *data);
void					ft_bfs(t_data *data);

#endif
