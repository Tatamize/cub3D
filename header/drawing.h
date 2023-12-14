/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawing.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kito <kito@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 15:14:27 by kito          #+#    #+#                 */
/*   Updated: 2023/01/20 07:33:01 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAWING_H
# define DRAWING_H
# include "data_set.h"

void		draw_p(t_data *data, t_pos *pos);
void		draw_ray_onmap(t_pos *sta, t_pos *end, t_data *data);
int			get_tex_pos_x(t_pos *end, t_data *data, mlx_texture_t *tex);
uint32_t	get_tex_color(t_pos *end, t_data *data, float wall_h, int tex_y);
void		draw_wall_strip(t_pos *end, t_data *data, int i);
void		draw_floor_ceilling(t_data *data);
#endif
