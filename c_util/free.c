/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhoukes <lhoukes@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 17:48:56 by lhoukes       #+#    #+#                 */
/*   Updated: 2023/01/22 13:56:04 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header/data_set.h"

void	clean_textures(t_canvas *data)
{
	mlx_delete_texture(data->texdata_n);
	mlx_delete_texture(data->texdata_s);
	mlx_delete_texture(data->texdata_w);
	mlx_delete_texture(data->texdata_e);
}

void	clean_images(t_data *data)
{
	mlx_delete_image(data->canvas->canv, data->minimap->mini_img);
	mlx_delete_image(data->canvas->canv, data->minimap->mini_p);
	mlx_delete_image(data->canvas->canv, data->canvas->c_wall);
	mlx_delete_image(data->canvas->canv, data->canvas->c_img);
}

void	free_array(t_data *data)
{
	int	i;

	i = 0;
	if (data->map_s)
	{
		while (i < data->map->height)
		{
			free(data->map_s[i]);
			i++;
		}
	}
}

void	free_data(t_data *data)
{
	free(data->deco->tex_n);
	free(data->deco->tex_s);
	free(data->deco->tex_w);
	free(data->deco->tex_e);
	free(data->pos);
	free(data->map);
	free(data->deco);
	free(data->minimap);
	free(data->map_s);
	free(data->canvas);
}

void	clean_up(t_data *data)
{
	clean_textures(data->canvas);
	clean_images(data);
	free_array(data);
	free_data(data);
}
