/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kito <kito@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 15:14:27 by kito          #+#    #+#                 */
/*   Updated: 2023/01/20 08:41:14 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "../header/data_set.h"

/* 	
	convert the texture data's x and y coordinate
*/
void	convert_texture_wh(mlx_texture_t *new, mlx_texture_t *ori)
{
	int	w;
	int	x;
	int	y;

	y = 0;
	new->width = ori->height;
	new->height = ori->width;
	w = new->width;
	while (y < (int)new->height)
	{
		x = 0;
		while (x < w)
		{
			new->pixels[(y * w + x) * 4]
				= ori->pixels[(x * ori->width + y) * 4];
			new->pixels[(y * w + x) * 4 + 1]
				= ori->pixels[(x * ori->width + y) * 4 + 1];
			new->pixels[(y * w + x) * 4 + 2]
				= ori->pixels[(x * ori->width + y) * 4 + 2];
			new->pixels[(y * w + x) * 4 + 3]
				= ori->pixels[(x * ori->width + y) * 4 + 3];
			x++;
		}
		y++;
	}
}

/* 	
	get color with darker information (far wall will be darker)
*/
uint32_t	get_color(uint8_t *pixel, float darker)
{
	uint32_t	color;
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
	uint8_t		a;

	(void)(darker);
	r = *(pixel++) * darker;
	g = *(pixel++) * darker;
	b = *(pixel++) * darker;
	a = *(pixel++);
	color = r << 24 | g << 16 | b << 8 | a;
	return (color);
}

/* 	
	load texture file and convert the x-y data coordinate
*/
mlx_texture_t	*set_texture(char *path)
{
	mlx_texture_t	*temptex;
	mlx_texture_t	*newtex;

	temptex = mlx_load_png(path);
	if (!temptex)
		exit_this_way(R199"Loading png file failed\n"RESET, false);
	newtex = mlx_load_png(path);
	if (!newtex)
		exit_this_way(R199"Loading png file failed\n"RESET, false);
	convert_texture_wh(newtex, temptex);
	mlx_delete_texture(temptex);
	return (newtex);
}
