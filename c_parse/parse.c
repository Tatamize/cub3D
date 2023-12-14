/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhoukes <lhoukes@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/17 17:12:37 by lhoukes       #+#    #+#                 */
/*   Updated: 2023/01/22 20:14:11 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header/data_set.h"
#include "../header/parse.h"

/* 
	check the 6 resources(textiles and colors) are all set.
	If all information is ready, check_data func starts to parse map
*/
bool	resource_ready(t_data *data)
{
	if (data->deco->color_f == 0 || data->deco->color_c == 0)
		return (false);
	if (!data->deco->tex_n || !data->deco->tex_s \
		|| !data->deco->tex_w || !data->deco->tex_e)
		return (false);
	return (true);
}

/*	
	make mapdata(2d strings array) by linked list.
	for mapdata, fill all string data with ' ', and after that
	copy the information (of wall(1), space(0), and player(SNWE)0) on it.
*/
void	make_mapdata(t_data *data, t_check_map *cm)
{
	t_mapline	*current;
	int			coll;
	char		*st;
	int			row;

	current = cm->begin;
	row = 0;
	data->map_s = protect_check(malloc(sizeof(char *) * (cm->maxline + 1)));
	data->map_s[cm->maxline] = NULL;
	while (current)
	{
		st = protect_check(malloc(sizeof(char) * (cm->maxcol + 1)));
		ft_memset(st, ' ', cm->maxcol);
		coll = 0;
		while (current->str[coll])
		{
			st[coll] = current->str[coll];
			coll++;
		}
		st[cm->maxcol] = '\0';
		data->map_s[row] = st;
		row++;
		current = current->next;
	}
}
