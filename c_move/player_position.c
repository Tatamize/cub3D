/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_position.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhoukes <lhoukes@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/17 16:32:51 by lhoukes       #+#    #+#                 */
/*   Updated: 2023/01/23 15:25:51 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../header/data_set.h"

/*	
	check the player (only 1 in the map), and set the direction
*/
void	check_player_direction(t_mapline *current, t_data *data, int i)
{
	if (!(current->str[i] == '1' || current->str[i] == '0' \
		|| current->str[i] == ' '))
	{
		if (current->str[i] == 'N' && data->pos->dir == -1.0)
			set_dir(data->pos, 0.0);
		else if (current->str[i] == 'S' && data->pos->dir == -1.0)
			set_dir(data->pos, 180.0);
		else if (current->str[i] == 'W' && data->pos->dir == -1.0)
			set_dir(data->pos, 270.0);
		else if (current->str[i] == 'E' && data->pos->dir == -1.0)
			set_dir(data->pos, 90.0);
		else
			exit_this_way(B31"Data is not valid\n"RESET, false);
	}
}

/*	
	check if player position is right(on the edge of data is invalid).
	check if player touchs empty space(' ') -> invalid
*/
void	check_player_surrounding(t_data *data, int c, int l)
{
	if (l == 0 || l == data->map->height - 1 || c == 0 || \
		c == data->map->width - 1)
		exit_this_way(R009"Player is on the border of map\n"RESET, false);
	if (data->map_s[l][c - 1] == ' ' || data->map_s[l][c + 1] == ' ' \
		|| data->map_s[l - 1][c] == ' ' || data->map_s[l + 1][c] == ' ')
		exit_this_way(R200"Player touches the space\n"RESET, false);
}

/*	
	check around the player, and if ok, set the start position 
*/
void	check_position(t_data *data)
{
	int	c;
	int	l;

	c = 0;
	l = 0;
	while (l < data->map->height)
	{
		c = 0;
		while (data->map_s[l][c])
		{
			if (data->map_s[l][c] == 'N' || data->map_s[l][c] == 'S' || \
				data->map_s[l][c] == 'W' || data->map_s[l][c] == 'E')
			{
				check_player_surrounding(data, c, l);
				data->pos->x = c * data->map->gs + (data->map->gs / 2);
				data->pos->y = l * data->map->gs + (data->map->gs / 2);
			}
			c++;
		}
		l++;
	}
}
