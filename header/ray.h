/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kito <kito@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/17 15:48:55 by kito          #+#    #+#                 */
/*   Updated: 2023/01/22 14:03:30 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H
# include "data_set.h"

float	x_cross_hori_y(t_pos *raypos, int hori_y);
float	y_cross_vert_x(t_pos *raypos, int vert_x);
bool	ray_touch_wall_hori(t_data *data, float x, float y, t_pos *raypos);
bool	ray_touch_wall_ver(t_data *data, float x, float y, t_pos *raypos);
void	get_rays(t_data *data);

#endif