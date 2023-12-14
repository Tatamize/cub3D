/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook_move.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kito <kito@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/17 19:48:37 by kito          #+#    #+#                 */
/*   Updated: 2023/01/20 07:46:23 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../header/data_set.h"
#include "../header/hook.h"

void	move_forward(t_data *d)
{
	if (!touch_wall(d, d->pos->x + cor_x(d->pos, d->map->speed), d->pos->y))
		d->pos->x += cor_x(d->pos, d->map->speed);
	if (!touch_wall(d, d->pos->x, d->pos->y + cor_y(d->pos, d->map->speed)))
		d->pos->y += cor_y(d->pos, d->map->speed);
}

void	move_backward(t_data *d)
{
	if (!touch_wall(d, d->pos->x - cor_x(d->pos, d->map->speed), d->pos->y))
		d->pos->x -= cor_x(d->pos, d->map->speed);
	if (!touch_wall(d, d->pos->x, d->pos->y - cor_y(d->pos, d->map->speed)))
		d->pos->y -= cor_y(d->pos, d->map->speed);
}

void	move_left(t_data *d)
{
	float	ldir;
	t_pos	temp;

	ldir = d->pos->dir - 90.0;
	if (ldir < 0.0)
		ldir += 360.0;
	set_dir(&temp, ldir);
	if (!touch_wall(d, d->pos->x + cor_x(&temp, d->map->speed), d->pos->y))
		d->pos->x += cor_x(&temp, d->map->speed);
	if (!touch_wall(d, d->pos->x, d->pos->y + cor_y(&temp, d->map->speed)))
		d->pos->y += cor_y(&temp, d->map->speed);
}

void	move_right(t_data *d)
{
	float	rdir;
	t_pos	temp;

	rdir = d->pos->dir + 90.0;
	if (rdir >= 360.0)
		rdir -= 360.0;
	set_dir(&temp, rdir);
	if (!touch_wall(d, d->pos->x + cor_x(&temp, d->map->speed), d->pos->y))
		d->pos->x += cor_x(&temp, d->map->speed);
	if (!touch_wall(d, d->pos->x, d->pos->y + cor_y(&temp, d->map->speed)))
		d->pos->y += cor_y(&temp, d->map->speed);
}
