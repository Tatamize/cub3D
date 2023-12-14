/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   canvas.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kito <kito@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 15:14:27 by kito          #+#    #+#                 */
/*   Updated: 2023/01/17 20:35:30 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../header/data_set.h"
#include "../header/texture.h"
#include "../header/canvas.h"
#include "../header/hook.h"
#include "../header/ray.h"
#include "../header/drawing.h"

/* 
	initialize canvas(mlx) and make images (for background and wall).
	paint ceiling and floor, get the texture data.
*/
void	canvas_init(t_data *d)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	d->canvas->canv = mlx_init(d->map->sw, d->map->sh, "cub3D", true);
	if (!d->canvas->canv)
		exit_this_way(R199"MLX42 mlx_init failed\n"RESET, false);
	d->canvas->c_img = mlx_new_image(d->canvas->canv, d->map->sw, d->map->sh);
	d->canvas->c_wall = mlx_new_image(d->canvas->canv, d->map->sw, d->map->sh);
	if (!d->canvas->c_img || !d->canvas->c_wall)
		exit_this_way(R199"mlx_new_image for canvas failed\n"RESET, false);
	draw_floor_ceilling(d);
	d->canvas->texdata_n = set_texture(d->deco->tex_n);
	d->canvas->texdata_e = set_texture(d->deco->tex_e);
	d->canvas->texdata_s = set_texture(d->deco->tex_s);
	d->canvas->texdata_w = set_texture(d->deco->tex_w);
}

/* 
	fill the wall grid on minimap
*/
void	print_wall_ongrid(t_data *d)
{
	int	l;
	int	c;

	l = 0;
	c = 0;
	while (l < d->map->height)
	{
		c = 0;
		while (c < d->map->width)
		{
			if (d->map_s[l][c] == '1')
				fill_grid(d, c, l, 0x54503BFF);
			c++;
		}
		l++;
	}
}

/* 
	clean up data when the exit button (left top corner of window) is clicked
*/
void	exit_on_click(void *param)
{
	t_data	*data;

	data = param;
	clean_up(data);
	mlx_terminate(data->canvas->canv);
	exit_this_way(R200"\nThank you for playing.\n", true);
}

/* 
	make canvas(mlx) and all images(background, wall, minimap, player),
	calculate ray distance and set data for all elements(wall, player, ray).
	set hook and start loop.
*/
void	make_canvas(t_data *d)
{
	canvas_init(d);
	minimap_init(d);
	print_grid(d);
	print_wall_ongrid(d);
	get_rays(d);
	mlx_image_to_window(d->canvas->canv, d->minimap->mini_img, 0, 0);
	mlx_image_to_window(d->canvas->canv, d->minimap->mini_p, 0, 0);
	mlx_image_to_window(d->canvas->canv, d->canvas->c_img, 0, 0);
	mlx_image_to_window(d->canvas->canv, d->canvas->c_wall, 0, 0);
	mlx_loop_hook(d->canvas->canv, &hook, d);
	mlx_key_hook(d->canvas->canv, &keyhook, d);
	mlx_close_hook(d->canvas->canv, exit_on_click, d);
	mlx_loop(d->canvas->canv);
}
