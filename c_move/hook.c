/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kito <kito@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/17 19:40:34 by kito          #+#    #+#                 */
/*   Updated: 2023/01/22 11:41:16 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../header/data_set.h"
#include "../header/ray.h"
#include "../header/hook.h"

/* 	
	calculate distance between 2 points.
	if the 2 points position is same, it returns 1 to avoid infinit wall height
*/
float	check_distance(float x, float y, float xx, float yy)
{
	float	dis;

	if (x == xx && y == yy)
		dis = 1.0;
	else
		dis = sqrt((x - xx) * (x - xx) + (y - yy) * (y - yy));
	return (dis);
}

/* 	
	check if the point is inside wall or not
*/
bool	touch_wall(t_data *d, float x, float y)
{
	int	grid_x;
	int	grid_y;

	grid_x = floor(x / d->map->gs);
	grid_y = floor(y / d->map->gs);
	if (d->map_s[grid_y][grid_x] == '1')
		return (1);
	else
		return (0);
}

void	hook(void *param)
{
	t_data	*d;

	d = param;
	if (mlx_is_key_down(d->canvas->canv, MLX_KEY_UP)
		|| mlx_is_key_down(d->canvas->canv, MLX_KEY_W))
		move_forward(d);
	else if (mlx_is_key_down(d->canvas->canv, MLX_KEY_DOWN)
		|| mlx_is_key_down(d->canvas->canv, MLX_KEY_S))
		move_backward(d);
	else if (mlx_is_key_down(d->canvas->canv, MLX_KEY_LEFT))
		turn_left(d->pos);
	else if (mlx_is_key_down(d->canvas->canv, MLX_KEY_RIGHT))
		turn_right(d->pos);
	else if (mlx_is_key_down(d->canvas->canv, MLX_KEY_A))
		move_left(d);
	else if (mlx_is_key_down(d->canvas->canv, MLX_KEY_D))
		move_right(d);
	else
		return ;
	get_rays(d);
}

/* 	
	change the layer order of minimap and main background and wall
*/
void	switch_minimap(t_data *d, int show)
{
	if (show == 1)
	{
		d->minimap->map_show = 1;
		mlx_set_instance_depth(d->canvas->c_img->instances, 0);
		mlx_set_instance_depth(d->canvas->c_wall->instances, 1);
		mlx_set_instance_depth(d->minimap->mini_img->instances, 2);
		mlx_set_instance_depth(d->minimap->mini_p->instances, 3);
	}
	else
	{
		d->minimap->map_show = 0;
		mlx_set_instance_depth(d->minimap->mini_img->instances, 0);
		mlx_set_instance_depth(d->minimap->mini_p->instances, 1);
		mlx_set_instance_depth(d->canvas->c_img->instances, 2);
		mlx_set_instance_depth(d->canvas->c_wall->instances, 3);
	}
}

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_data	*d;

	d = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(d->canvas->canv);
	if (keydata.key == MLX_KEY_Q && keydata.action == MLX_PRESS)
		mlx_close_window(d->canvas->canv);
	if (keydata.key == MLX_KEY_M
		&& keydata.action == MLX_PRESS && d->minimap->map_show == 0)
		switch_minimap(d, 1);
	else if (keydata.key == MLX_KEY_M
		&& keydata.action == MLX_PRESS && d->minimap->map_show == 1)
		switch_minimap(d, 2);
	else
		return ;
	get_rays(d);
}
