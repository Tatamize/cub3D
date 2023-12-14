/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kito <kito@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/17 20:28:37 by kito          #+#    #+#                 */
/*   Updated: 2023/01/22 20:13:40 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../header/data_set.h"
#include "../libft/libft.h"
#include "../header/canvas.h"
#include "../header/ray.h"
#include "../header/drawing.h"

/* 	
	find horizontal hitting point to the wall.
	at first, check the closest horizontal crossing point.
	and move to next horizontal grid line one by one.
	check each time if the point hits the wall.
	set the wall type after finding hit point.
*/
t_pos	*get_hori_hitpoint(t_data *data, t_pos *raypos, t_pos *hit)
{
	float	step_h;

	if (raypos->updown == 1)
		hit->y = floor(raypos->y / data->map->gs) \
			* data->map->gs + data->map->gs;
	if (raypos->updown == -1)
		hit->y = (floor(raypos->y / data->map->gs) * data->map->gs);
	hit->x = x_cross_hori_y(raypos, hit->y);
	step_h = data->map->gs * tan(raypos->rad_y);
	while (hit->x < data->map->width * data->map->gs
		&& hit->y < data->map->height * data->map->gs
		&& hit->x > 0 && hit->y > 0
		&& !ray_touch_wall_hori(data, hit->x, hit->y, raypos))
	{
		hit->y += data->map->gs * raypos->updown;
		hit->x += step_h * raypos->rightleft;
	}
	hit->walltype = 2 * raypos->updown;
	return (hit);
}

/* 	
	find vertical hitting point to the wall.
	(same as horizontal function above)
*/
t_pos	*get_ver_hitpoint(t_data *data, t_pos *raypos, t_pos *hit)
{
	float	step_v;

	if (raypos->rightleft == 1)
		hit->x = floor(raypos->x / data->map->gs) \
			* data->map->gs + data->map->gs;
	if (raypos->rightleft == -1)
		hit->x = (floor(raypos->x / data->map->gs) * data->map->gs);
	hit->y = y_cross_vert_x(raypos, hit->x);
	step_v = data->map->gs * tan(raypos->rad_x);
	while (hit->x < data->map->width * data->map->gs
		&& hit->y < data->map->height * data->map->gs
		&& hit->x > 0 && hit->y > 0
		&& !ray_touch_wall_ver(data, hit->x, hit->y, raypos))
	{
		hit->x += data->map->gs * raypos->rightleft;
		hit->y += step_v * raypos->updown;
	}
	hit->walltype = 1 * raypos->rightleft;
	return (hit);
}

void	draw_ray_and_wall(t_data *data, t_pos *raypos, int i, t_pos *cross)
{
	draw_ray_onmap(raypos, cross, data);
	draw_wall_strip(cross, data, i);
}

/* 	
	find horizontal hitting point to the wall and
	vertical hitting point to the wall.
	Compare the 2 distances, and draw the ray to the nearest one.
*/
void	throw_ray(t_data *data, t_pos *raypos, int i)
{
	t_pos	cross_h;
	t_pos	cross_v;
	float	dis_h;
	float	dis_v;

	if (raypos->updown == 0)
	{
		get_ver_hitpoint(data, raypos, &cross_v);
		return (draw_ray_and_wall(data, raypos, i, &cross_v));
	}
	if (raypos->rightleft == 0)
	{
		get_hori_hitpoint(data, raypos, &cross_h);
		return (draw_ray_and_wall(data, raypos, i, &cross_h));
	}
	get_ver_hitpoint(data, raypos, &cross_v);
	get_hori_hitpoint(data, raypos, &cross_h);
	dis_v = check_distance(raypos->x, raypos->y, cross_v.x, cross_v.y);
	dis_h = check_distance(raypos->x, raypos->y, cross_h.x, cross_h.y);
	if (dis_v <= dis_h)
		draw_ray_and_wall(data, raypos, i, &cross_v);
	else
		draw_ray_and_wall(data, raypos, i, &cross_h);
	return ;
}

/* 	
	get_rays is called each time when player moved.
	raypos contains the position of player and the current ray direction.
	i indicates how many times the ray is drawn.
	rad is radian size between each ray.
*/
void	get_rays(t_data *data)
{
	t_pos	raypos;
	int		i;
	float	rad;

	i = 0;
	rad = 60.0 * data->map->wide / data->map->sw;
	raypos.x = data->pos->x;
	raypos.y = data->pos->y;
	draw_p(data, data->pos);
	ft_memset(data->canvas->c_wall->pixels, 0xFFFFFF00,
		data->canvas->c_wall->width * data->canvas->c_wall->height * 4);
	raypos.dir = data->pos->dir - 30.0;
	if (raypos.dir < 0.0)
		raypos.dir = 360.0 + raypos.dir;
	while (i < data->map->sw / data->map->wide)
	{
		set_dir(&raypos, raypos.dir);
		throw_ray(data, &raypos, i);
		raypos.dir += rad;
		if (raypos.dir > 360.0)
			raypos.dir = 360.0 - raypos.dir;
		i++;
	}	
}
