/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   canvas.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kito <kito@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 15:14:27 by kito          #+#    #+#                 */
/*   Updated: 2023/01/17 20:57:52 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_H
# define CANVAS_H
# include "data_set.h"

void	print_grid(t_data *d);
void	fill_grid(t_data *d, int x, int y, uint32_t color);
void	minimap_init(t_data *d);

float	check_distance(float x, float y, float xx, float yy);
bool	touch_wall(t_data *data, float x, float y);

void	print_wall_ongrid(t_data *d);
void	make_canvas(t_data *data);

#endif