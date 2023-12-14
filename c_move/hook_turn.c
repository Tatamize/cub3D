/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook_turn.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kito <kito@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/17 19:49:21 by kito          #+#    #+#                 */
/*   Updated: 2023/01/20 08:58:52 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../header/data_set.h"
#include "../header/hook.h"

float	cor_x(t_pos *pos, float dis)
{
	float		newx;

	newx = cos(pos->rad_x) * dis * pos->rightleft;
	return (newx);
}

float	cor_y(t_pos *pos, float dis)
{
	float		newy;

	newy = cos(pos->rad_y) * dis * pos->updown;
	return (newy);
}

void	turn_left(t_pos *pos)
{
	if (pos->dir < 0)
		pos->dir = 360 + pos->dir;
	pos->dir -= 4;
	set_dir(pos, pos->dir);
}

void	turn_right(t_pos *pos)
{
	if (pos->dir >= 360)
		pos->dir = 360 - pos->dir;
	pos->dir += 4;
	set_dir(pos, pos->dir);
}
