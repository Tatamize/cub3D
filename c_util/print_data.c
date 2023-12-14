/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_data.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhoukes <lhoukes@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 12:19:36 by lhoukes       #+#    #+#                 */
/*   Updated: 2023/01/22 12:53:03 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header/data_set.h"

void	print_map(t_data *data)
{
	printf("map width and height: %d, %d. grid size: %d\n", \
		data->map->width, data->map->height, data->map->gs);
	printf("screen width and height :%d, %d. wall height: %d\n", \
		data->map->sw, data->map->sh, data->map->wall);
}

void	print_deco(t_data *data)
{
	printf("floor color, ceiling color: %X, %X\n", \
		data->deco->color_f, data->deco->color_c);
	printf("texture N S W E :%s, %s, %s, %s.\n", data->deco->tex_n, \
		data->deco->tex_s, data->deco->tex_w, data->deco->tex_e);
}

void	print_data(t_data *data)
{
	print_map(data);
	print_deco(data);
}

void	print_map_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map->height)
	{
		printf(GRN"line is %s\n"RESET, data->map_s[i]);
		i++;
	}
}
