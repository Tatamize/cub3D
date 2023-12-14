/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawing_util.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kito <kito@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 15:14:27 by kito          #+#    #+#                 */
/*   Updated: 2023/01/20 08:57:18 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../header/data_set.h"
#include "../header/drawing.h"
#include "../header/canvas.h"
#include "../header/texture.h"

/* 	
	to draw the player on minimap as a circle(4px radius).
*/
void	draw_p(t_data *data, t_pos *pos)
{
	int		i;
	int		j;
	float	shrink;

	i = 0;
	j = 0;
	shrink = (float)data->minimap->mini_grid / data->map->gs;
	while (j < data->minimap->mini_grid * data->map->height)
	{
		i = 0;
		while (i < data->minimap->mini_grid * data->map->width)
		{
			if (check_distance(pos->x * shrink, pos->y * shrink, i, j) < 4.0)
				mlx_put_pixel(data->minimap->mini_p, i, j, 0xFF0000FF);
			else
				mlx_put_pixel(data->minimap->mini_p, i, j, 0xFFFFFF00);
			i++;
		}
		j++;
	}
}

/* 	
	to indicate the dierction to draw the line
*/
int	get_dir_move(float a, float b)
{
	if (a > b)
		return (-1);
	return (1);
}

/* 	
	to draw the ray line on the minimap
*/
void	draw_ray_onmap(t_pos *sta, t_pos *end, t_data *data)
{
	int		i;
	int		min;
	float	step;
	float	shrink;

	i = 0;
	min = get_dir_move(sta->x, end->x);
	shrink = (float)data->minimap->mini_grid / data->map->gs;
	step = (end->y - sta->y) / (end->x - sta->x);
	while ((int)(sta->x + i) != (int)(end->x))
	{
		mlx_put_pixel(data->minimap->mini_p, (int)(sta->x + i) * shrink,
			(int)(sta->y + step * i) * shrink, 0xF7A11577);
		i += min;
	}
	min = get_dir_move(sta->y, end->y);
	i = 0;
	step = (end->x - sta->x) / (end->y - sta->y);
	while ((int)(sta->y + i) != (int)(end->y))
	{
		mlx_put_pixel(data->minimap->mini_p, (int)(sta->x + step * i) * shrink,
			(int)(sta->y + i) * shrink, 0xF7A11577);
		i += min;
	}
}

/* 	
	to get the position data(x position) on the texture data.
	walltype 1 = East wall, 
	walltype -1 = West wall, 
	walltype 2 = South wall, 
	walltype -2 = north wall, 
*/
int	get_tex_pos_x(t_pos *end, t_data *data, mlx_texture_t *tex)
{
	float	pos_x;
	int		tex_x;
	int		gs;

	pos_x = 0;
	gs = data->map->gs;
	if (end->walltype == -1)
		pos_x = gs - (end->y - (gs * (int)(end->y / gs)));
	else if (end->walltype == 1)
		pos_x = (end->y - (gs * (int)(end->y / gs)));
	else if (end->walltype == 2)
		pos_x = gs - (end->x - (gs * (int)(end->x / gs)));
	else
		pos_x = (end->x - (gs * (int)(end->x / gs)));
	tex_x = pos_x * tex->height / gs;
	return (tex_x);
}

/* 	
	to get the color from the texture data.
	walltype 1 = East wall, 
	walltype -1 = West wall, 
	walltype 2 = South wall, 
	walltype -2 = north wall,
	tex_x might be same as the textile height, (and overflow) so do minus 1
*/
uint32_t	get_tex_color(t_pos *end, t_data *data, float wall_h, int tex_y)
{
	mlx_texture_t	*tex;
	float			wall_gs_h;
	int				tex_x;
	float			darker;

	darker = data->map->sh - wall_h;
	if (darker <= 0)
		darker = 1;
	else
		darker = 1.0 - (darker / data->map->sh * 0.2);
	if (end->walltype == 1)
		tex = data->canvas->texdata_e;
	else if (end->walltype == -1)
		tex = data->canvas->texdata_w;
	else if (end->walltype == 2)
		tex = data->canvas->texdata_s;
	else
		tex = data->canvas->texdata_n;
	tex_x = get_tex_pos_x(end, data, tex);
	wall_gs_h = (float)tex->width / wall_h;
	if (tex_x == (int)tex->height)
		tex_x = tex->height - 1;
	return (get_color(&tex->pixels[(int)(tex_x) *(int)tex->width * 4
			+ (int)(tex_y *(wall_gs_h))*4], darker));
}
