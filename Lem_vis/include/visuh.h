/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visuh.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohachim <ohachim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 21:31:52 by ohachim           #+#    #+#             */
/*   Updated: 2019/11/12 18:10:12 by ohachim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUH_H
# define VISUH_H

# define WIDTH 1600
# define HEIGHT 1600

# include "libft.h"
# include <SDL.h>
# include <SDL_image.h>
# include <stdlib.h>

typedef struct			s_cord
{
	int					x;
	int					y;
}						t_cord;
typedef struct			s_visud
{
	SDL_Window			*window;
	SDL_Surface			*screen_surface;
	SDL_Texture			*background_t;
	SDL_Renderer		*renderer;
	SDL_Event			e;
	SDL_Texture			*ant_t;
	SDL_Texture			*end;
	SDL_Texture			*start;
	SDL_Texture			*room;
	SDL_Texture			*menu;
	int					restart;
	int					help;
	int					scale;
	int					quit;
	int					speed;
	int					arrived;
	int					init;
	int					move_sum;
	int					pause;
	struct s_rooms		*rooms;
}						t_visud;
typedef struct			s_ants
{
	struct s_vertices	*destination;
	int					x;
	int					y;
	double				t;
	int					arrived;
}						t_ants;
typedef struct			s_rooms
{
	int					x;
	int					y;

}						t_rooms;
typedef struct			s_edges
{
	struct s_vertices	*connection;
	struct s_edges		*next;
}						t_edges;

typedef struct			s_input
{
	char				*line;
	struct s_input		*next;
}						t_input;

typedef struct			s_vertices
{
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
	int					max_x;
	int					max_y;
	int					room_size;
	struct s_vertices	**hash_table;
	struct s_vertices	**vertex_ray;
	struct s_vertices	*start;
	struct s_vertices	*end;
	struct s_input		*input_head;
	struct s_input		*moves_head;
	struct s_input		*remember_moves;
	struct s_ants		*motion_ant;
}						t_data;

void					ft_init_ants(t_data *data);
void					ft_draw_menu(t_visud *visud);
SDL_Texture				*ft_load_texture(char *path, t_visud *visud);
void					ft_zoom(t_visud *visud, int key);
int						ft_normalize_vertices(t_data *data);
void					ft_get_events(t_visud *visud, t_data *data);
void					ft_draw_edges(t_visud *visud, t_vertices *room,
						int size);
int						ft_check_validity(t_data *data, char *name,
						char *connection);
char					*ft_extract_edge(char *line);
char					*ft_extract_connection(char *line);
int						ft_create_edges(t_data *data);
int						ft_create_data(t_data *data);
int						ft_get_input(t_data *data);
int						ft_append_vertex(t_data *data, int hash,
						char *line, int vertex_position);
int						ft_create_hash(t_data *data);
int						ft_error_input(char *line);
char					*ft_extract_name(char *line);
int						ft_get_input(t_data *data);
void					ft_parse(t_data *data);
int						ft_hash_it(char *name, int vertices);
void					ft_initialize_hdata(t_data *data);
void					ft_free_data(t_data *data);
int						ft_init_visualization(t_visud *visud);
void					ft_draw_rooms(t_data *data, t_visud *visud, int init);
void					ft_copy_ants(t_data *data, t_visud *visud);
int						ft_draw_ants(t_visud *visud, t_data *data);
void					ft_braze_red(t_ants *ant, t_visud *visud);
void					ft_navigate(t_data *data, int key, t_visud *visud);

#endif
