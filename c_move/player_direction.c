/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_direction.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhoukes <lhoukes@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/17 16:59:03 by lhoukes       #+#    #+#                 */
/*   Updated: 2023/01/22 14:00:53 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../header/data_set.h"

/*	
	set the direction data.
	rad_y is radius from vertical line
	rad_x is radius from horizontal line
*/
static void	set_direction_one_eighty(t_pos *pos, float d)
{
	if (d == 180.0)
		pos->updown = 1;
	else
		pos->updown = -1;
	pos->rightleft = 0;
	pos->rad_y = 0.0;
	pos->rad_x = 90.0 * M_PI / 180;
}

static void	set_direction_two_seventy(t_pos *pos, float d)
{
	if (d == 270.0)
		pos->rightleft = -1;
	else
		pos->rightleft = 1;
	pos->updown = 0;
	pos->rad_y = 90.0 * M_PI / 180;
	pos->rad_x = 0.0;
}

static void	set_direction_half_way(t_pos *pos, float d)
{
	pos->updown = 1;
	pos->rightleft = 1;
	pos->rad_y = (180.0 - d) * M_PI / 180;
	pos->rad_x = (d - 90.0) * M_PI / 180;
}

static void	set_direction_up_to_three_sixty(t_pos *pos, float d)
{
	pos->updown = -1;
	pos->rightleft = -1;
	pos->rad_y = (360.0 - d) * M_PI / 180;
	pos->rad_x = (d - 270.0) * M_PI / 180;
}

void	set_dir(t_pos *pos, float d)
{
	pos->dir = d;
	if (d == 0.0 || d == 180.0)
		set_direction_one_eighty(pos, d);
	if (d == 90.0 || d == 270.0)
		set_direction_two_seventy(pos, d);
	if (d > 0.0 && d < 90.0)
	{
		pos->updown = -1;
		pos->rightleft = 1;
		pos->rad_y = d * M_PI / 180;
		pos->rad_x = (90.0 - d) * M_PI / 180;
	}
	if (d > 90.0 && d < 180.0)
		set_direction_half_way(pos, d);
	if (d > 180.0 && d < 270.0)
	{
		pos->updown = 1;
		pos->rightleft = -1;
		pos->rad_y = (d - 180.0) * M_PI / 180;
		pos->rad_x = (270.0 - d) * M_PI / 180;
	}
	if (d > 270.0 && d < 360.0)
		set_direction_up_to_three_sixty(pos, d);
}
