/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_wall.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kito <kito@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 15:14:27 by kito          #+#    #+#                 */
/*   Updated: 2023/01/20 08:43:22 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header/data_set.h"
#include "../header/parse.h"

/*	
	check if a space(0) position is right(on the edge of data is invalid).
	check if a space(0) touchs empty space(' ') -> invalid
*/
static void	is_wall_closed(t_data *data, int c, int l)
{
	if (l == 0 || l == data->map->height - 1)
		exit_this_way(R199"0 is on the horizontal edge\n"RESET, false);
	if (c == 0 || c == data->map->width - 1)
		exit_this_way(R199"0 is on the vertical edge\n"RESET, false);
	if (data->map_s[l][c - 1] == ' ' || data->map_s[l][c + 1] == ' ')
		exit_this_way(R199"Spase is a side of 0\n"RESET, false);
	if (data->map_s[l - 1][c] == ' ' || data->map_s[l + 1][c] == ' ')
		exit_this_way(R199"Spase is above or below of 0\n"RESET, false);
}

/*	
	check if the all space(0) and player are surrounded by the wall(1)
*/
void	check_wall(t_data *data)
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
			if (data->map_s[l][c] == '0')
				is_wall_closed(data, c, l);
			c++;
		}
		l++;
	}
}
