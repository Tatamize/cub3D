/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_data.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhoukes <lhoukes@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 14:31:38 by lhoukes       #+#    #+#                 */
/*   Updated: 2023/01/23 09:55:54 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header/data_set.h"

/* inits the data */

void	init_cmap(t_check_map *cm)
{
	cm->maxcol = 0;
	cm->maxline = 0;
	cm->begin = NULL;
	cm->last = NULL;
}

void	malloc_data(t_data *data)
{
	data->pos = protect_check(malloc(sizeof(t_pos) * 1));
	data->map = protect_check(malloc(sizeof(t_map) * 1));
	data->deco = protect_check(malloc(sizeof(t_deco) * 1));
	data->minimap = protect_check(malloc(sizeof(t_minimap) * 1));
	data->canvas = protect_check(malloc(sizeof(t_canvas) * 1));
}

void	init_data(t_data *data)
{
	malloc_data(data);
	data->map_s = NULL;
	data->pos->x = 0;
	data->pos->y = 0;
	data->pos->dir = -1.0;
	data->pos->rad_y = 0.0;
	data->pos->rad_x = 0.0;
	data->pos->updown = 0;
	data->pos->rightleft = 0;
	data->map->width = 0;
	data->map->height = 0;
	data->map->gs = 64;
	data->map->sw = 1200;
	data->map->sh = 800;
	data->map->wide = 1;
	data->map->speed = 10.0;
	data->map->wall = 1300;
	data->deco->color_f = 0;
	data->deco->color_c = 0;
	data->deco->tex_n = NULL;
	data->deco->tex_s = NULL;
	data->deco->tex_w = NULL;
	data->deco->tex_e = NULL;
	data->minimap->mini_grid = 12;
}
