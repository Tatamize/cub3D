/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minimap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kito <kito@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/17 19:52:16 by kito          #+#    #+#                 */
/*   Updated: 2023/01/22 13:27:27 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../libft/libft.h"
#include "../header/data_set.h"
#include "../header/texture.h"
#include "../header/canvas.h"
#include "../header/ray.h"
#include "../header/drawing.h"

/* 
	pring grid on minimap
*/
void	print_grid(t_data *d)
{
	int	i;
	int	j;
	int	gs;

	i = 0;
	j = 0;
	gs = d->minimap->mini_grid;
	while (i < d->map->width * d->map->height * gs * gs)
	{
		if (i % (d->minimap->mini_grid) == 0)
			mlx_put_pixel(d->minimap->mini_img,
				i % (d->map->width * gs), i / (d->map->width * gs), 0xCCCCCCFF);
		i++;
	}
	i = 0;
	while (i < d->map->height * gs)
	{
		if (i % gs == 0)
		{
			j = 0;
			while (j < d->map->width * gs)
				mlx_put_pixel(d->minimap->mini_img, j++, i, 0xCCCCCCFF);
		}
		i++;
	}
}

/* 
	fill grid(tile) on minimap
*/
void	fill_grid(t_data *d, int x, int y, uint32_t color)
{
	int	i;
	int	j;
	int	gs;

	i = 0;
	j = 0;
	gs = d->minimap->mini_grid;
	while (j < gs)
	{
		i = 0;
		while (i < gs)
		{
			mlx_put_pixel(d->minimap->mini_img, x * gs + i, y * gs + j, color);
			i++;
		}
		j++;
	}
}

/* 
	make images for minimap
*/
void	minimap_init(t_data *d)
{
	int	gs;

	if (d->map->width > 60 || d->map->height > 60)
		d->minimap->mini_grid = 6;
	if (d->map->width > 100 || d->map->height > 100)
		d->minimap->mini_grid = 4;
	if (d->map->width > 200 || d->map->height > 200)
		d->minimap->mini_grid = 2;
	gs = d->minimap->mini_grid;
	d->minimap->mini_img = mlx_new_image(d->canvas->canv,
			d->map->width * gs, d->map->height * gs);
	d->minimap->mini_p = mlx_new_image(d->canvas->canv,
			d->map->width * gs, d->map->height * gs);
	if (!d->minimap->mini_img || !d->minimap->mini_p)
		exit_this_way(R199"mlx_new_image for minimap failed\n"RESET, false);
	ft_memset(d->minimap->mini_img->pixels, 0xFFFFFFDD,
		d->minimap->mini_img->width * d->minimap->mini_img->height * 4);
	print_grid(d);
	print_wall_ongrid(d);
}
