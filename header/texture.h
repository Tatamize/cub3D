/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kito <kito@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 15:14:27 by kito          #+#    #+#                 */
/*   Updated: 2023/01/22 13:39:59 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H
# include "data_set.h"

void			convert_tex_wh(mlx_image_t *new, mlx_image_t *ori);
uint32_t		get_color(uint8_t *pixel, float darker);
mlx_texture_t	*set_texture(char *path);

#endif