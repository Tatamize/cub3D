/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   data_set.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhoukes <lhoukes@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 17:15:11 by lhoukes       #+#    #+#                 */
/*   Updated: 2023/01/22 11:33:31 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_SET_H
# define DATA_SET_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include "def.h"
# include "error.h"
# include "colors.h"

/* 
	@w width - number of charactors in map
	@h height - number of charactors in map
	@gs grid size - default 64
	@sw screen width - default 800
	@sh screen height - deafult 600
	@wide wall strip width - default 2px
	@speed step distance in one move - default 4.0
	@wall wall height (depends on cub size)
*/
typedef struct s_map
{
	int		gs;
	int		sw;
	int		sh;
	int		wide;
	float	speed;
	int		wall;
	int		width;
	int		height;	
}	t_map;

/*
	@color_f floor color
	@color_c ceiling color
	@tex_n	path for texture north
	@tex_s	path for texture south
	@tex_w	path for texture west
	@tex_e	path for texture east	
*/
typedef struct s_deco
{
	int		color_f;
	int		color_c;
	char	*tex_n;
	char	*tex_s;
	char	*tex_w;
	char	*tex_e;
}	t_deco;

/*
	@dir 360 degree direction in this moment. 0 is North, 90 is East, 
	180 is South, 270 is West
	@rad_y radius from y coordinate (ex: dir = 30 -> rad_y = 30)
	@rad_x radius from x coordinate (ex: dir = 30 -> rad_y = 60)
	@updown indicates the up(-1) or down(1) or horizontal(0) direction
	@leftright indicates the right(1) or left(-1) or vertical(0) direction
	@walltype indicates the wall type if this position is used for ray's end
*/
typedef struct s_pos
{
	float	x;
	float	y;
	float	dir;
	float	rad_y;
	float	rad_x;
	int		updown;
	int		rightleft;
	int		walltype;
}	t_pos;

/*
	struct for the textures and image on the canvas
*/
typedef struct s_canvas
{
	mlx_image_t		*c_img;
	mlx_image_t		*c_wall;
	mlx_t			*canv;
	mlx_texture_t	*texdata_n;
	mlx_texture_t	*texdata_s;
	mlx_texture_t	*texdata_e;
	mlx_texture_t	*texdata_w;
}	t_canvas;

/*
	Data for the minimap
*/
typedef struct s_minimap
{
	int			mini_grid;
	mlx_image_t	*mini_img;
	mlx_image_t	*mini_p;
	bool		map_show;
}	t_minimap;

/*
	general data for the map
	@map_s mapdata - 2d array -> needs to be freed
*/

typedef struct s_data
{
	t_pos		*pos;
	t_map		*map;
	t_deco		*deco;
	t_minimap	*minimap;
	t_canvas	*canvas;
	char		**map_s;
}	t_data;

typedef struct s_mapline	t_mapline;

/* 
	linked list to prepare the map
*/
typedef struct s_mapline
{
	char		*str;
	t_mapline	*next;
}	t_mapline;

typedef struct s_check_map
{
	int			maxcol;
	int			maxline;
	t_mapline	*begin;
	t_mapline	*last;
}	t_check_map;

/*
	functions to set all the data
*/
bool	is_correct_ext(char *argument, char *extension);
void	set_dir(t_pos *pos, float d);
void	check_player_direction(t_mapline *current, t_data *data, int i);
void	init_data(t_data *data);
void	free_data(t_data *data);
void	malloc_data(t_data *data);
void	init_cmap(t_check_map *cm);
bool	resource_ready(t_data *data);
void	count_mapsize(t_check_map *cm);
void	check_position(t_data *data);
void	check_wall(t_data *data);
void	make_mapdata(t_data *data, t_check_map *cm);
void	check_map_elements(t_data *data, t_check_map *cm);
void	clear_mapline(t_check_map *check_map_line);
void	clean_up(t_data *data);

#endif
