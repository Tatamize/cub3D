/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kito <kito@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/20 07:36:36 by kito          #+#    #+#                 */
/*   Updated: 2023/01/20 08:33:16 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H
# include "data_set.h"

float	cor_x(t_pos *pos, float dis);
float	cor_y(t_pos *pos, float dis);
void	turn_left(t_pos *pos);
void	turn_right(t_pos *pos);

void	move_forward(t_data *d);
void	move_backward(t_data *d);
void	move_left(t_data *d);
void	move_right(t_data *d);

float	check_distance(float x, float y, float xx, float yy);
bool	touch_wall(t_data *d, float x, float y);
void	hook(void *param);
void	keyhook(mlx_key_data_t keydata, void *param);

#endif
