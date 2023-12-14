/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray_util.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kito <kito@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/17 15:47:03 by kito          #+#    #+#                 */
/*   Updated: 2023/01/20 08:29:05 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../header/data_set.h"

/* 
	find the x value of closest horizontal line
*/
float	x_cross_hori_y(t_pos *raypos, int hori_y)
{
	float		newx;

	newx = 0;
	if (hori_y == -1)
		return (-1);
	newx = (fabs(hori_y - raypos->y)) / tan(raypos->rad_x) * raypos->rightleft;
	return (raypos->x + newx);
}

/* 
	find the y value of closest vertical line
*/
float	y_cross_vert_x(t_pos *raypos, int vert_x)
{
	float		newy;

	newy = 0;
	if (vert_x == -1)
		return (-1);
	newy = (fabs(vert_x - raypos->x)) / tan(raypos->rad_y) * raypos->updown;
	return (raypos->y + newy);
}

/* 
	check if the ray and horizontal grid crossing point hits wall or not
*/
bool	ray_touch_wall_hori(t_data *data, float x, float y, t_pos *raypos)
{
	int	grid_x;
	int	grid_y;

	if (raypos->updown == -1 && y > 1)
		grid_y = floor((y - 1) / data->map->gs);
	else
		grid_y = floor(y / data->map->gs);
	grid_x = floor(x / data->map->gs);
	if (data->map_s[grid_y][grid_x] == '1')
		return (1);
	else
		return (0);
}

/* 
	check if the ray and vertical grid crossing point hits wall or not
*/
bool	ray_touch_wall_ver(t_data *data, float x, float y, t_pos *raypos)
{
	int	grid_x;
	int	grid_y;
	// int	mod_x;

	// mod_x = 0;
	if (raypos->rightleft == -1 && x > 1)
		grid_x = floor((x - 1) / data->map->gs);
	else
		grid_x = floor(x / data->map->gs);
	grid_y = floor(y / data->map->gs);
	if (data->map_s[grid_y][grid_x] == '1')
		return (1);
	else
		return (0);
}
