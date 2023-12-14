/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kito <kito@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 15:14:27 by kito          #+#    #+#                 */
/*   Updated: 2023/01/23 09:54:16 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../header/data_set.h"
#include "../header/canvas.h"
#include "../header/drawing.h"
#include "../header/texture.h"

/* 	
	rad : find radian wide between each ray, and get the direction of current ray
	dis : get the distance to the wall, and modify the distortion
	wall height can be caliculated by the distance between the wall and player
*/
float	get_wall_height(t_pos *end, t_data *data, int i)
{
	float	wall;
	float	rad;
	float	dis;

	rad = 60.0 * data->map->wide / data->map->sw;
	dis = check_distance(data->pos->x, data->pos->y, end->x, end->y);
	dis = dis * cos((fabs(30 - rad * i)) * M_PI / 180);
	wall = (float)(data->map->wall / dis) * ((60 / 2) / tan(30.0 * M_PI / 180));
	return (wall);
}

/* 	
	wall : find wall height
	y : find y (starting point to print wall to the vertical direction)
	tex_y : the data position (y) in the texture data
	if y is minus, it means the wall starts out of screen
*/
void	draw_wall_strip(t_pos *end, t_data *data, int i)
{
	float	wall;
	int		x;
	int		y;
	int		tex_y;

	wall = get_wall_height(end, data, i);
	y = (data->map->sh - wall) / 2;
	tex_y = 0;
	if (y < 0)
	{
		tex_y = y * -1;
		y = 0;
	}
	while (y < (data->map->sh - wall) / 2 + wall - 1 && y < data->map->sh)
	{
		x = i * data->map->wide;
		while (x < i * data->map->wide + data->map->wide)
		{
			mlx_put_pixel(data->canvas->c_wall, x, y,
				get_tex_color(end, data, wall, tex_y));
			x++;
		}
		y++;
		tex_y++;
	}
}

/* 	
	draw ceilling and floor
*/
void	draw_floor_ceilling(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->map->sh)
	{
		x = 0;
		while (x < data->map->sw)
		{
			if (y < data->map->sh / 2)
				mlx_put_pixel(data->canvas->c_img, x, y, data->deco->color_c);
			else
				mlx_put_pixel(data->canvas->c_img, x, y, data->deco->color_f);
			x++;
		}
		y++;
	}
}
