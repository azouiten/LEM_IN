/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_inh.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:47:00 by ohachim           #+#    #+#             */
/*   Updated: 2019/10/06 17:16:04 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_INH_H
# define LEM_INH_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <libft.h>

typedef	struct			s_queue // new
{
	struct s_vertices	*item;
	struct s_queue		*last;
	struct s_queue		*next;
	struct s_paths		*path;
}						t_queue;

typedef	struct			s_paths // new
{
	char				*path;
	struct	s_paths		*next;
}						t_paths;

typedef struct			s_input
{
	char				*line;
	struct s_input		*next;
}						t_input;

typedef struct			s_edges
{
	int					status;
	struct s_vertices	*connection;
	struct s_edges		*next;
}						t_edges;

typedef struct			s_vertices
{
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
	struct s_vertices	**hash_table;
	struct s_vertices	*start;
	struct s_vertices	*end;
	struct s_input		*input_head;
	struct s_queue		*queue; // new
	struct s_paths		*paths; // new
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

#endif