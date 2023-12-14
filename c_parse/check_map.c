/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhoukes <lhoukes@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 17:47:10 by lhoukes       #+#    #+#                 */
/*   Updated: 2023/01/22 14:47:03 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header/data_set.h"
#include "../libft/libft.h"
#include "../header/parse.h"

/* 
	first, check the resource is already set or not.
	if not set, return allocated data with the texture file name
*/
char	*get_tex_data(char *s, char *texture)
{
	char	*tex_data;
	int		i;

	i = 0;
	while (s[i] == ' ')
		s++;
	i = 0;
	while (s[i] != ' ' && s[i] != '\0')
		i++;
	if (texture)
		exit_this_way(O202"Texture data is already set\n"RESET, false);
	tex_data = ft_substr(s, 0, i);
	if (!tex_data)
		exit_this_way(R199"Texture data string couldn't be made\n"RESET, false);
	if (is_correct_ext(tex_data, ".png") == false)
		exit_this_way(Y151"Texture data should be .png\n"RESET, false);
	return (tex_data);
}

/* 
	check the first sentence and set the resource information.
	free the string data (from GNL)
*/
void	check_resource(char *s, t_data *data)
{
	if (s[0] == 'N' && s[1] == 'O' && s[2] == ' ')
		data->deco->tex_n = get_tex_data(&s[3], data->deco->tex_n);
	else if (s[0] == 'S' && s[1] == 'O' && s[2] == ' ')
		data->deco->tex_s = get_tex_data(&s[3], data->deco->tex_s);
	else if (s[0] == 'W' && s[1] == 'E' && s[2] == ' ')
		data->deco->tex_w = get_tex_data(&s[3], data->deco->tex_w);
	else if (s[0] == 'E' && s[1] == 'A' && s[2] == ' ')
		data->deco->tex_e = get_tex_data(&s[3], data->deco->tex_e);
	else if (s[0] == 'F' && s[1] == ' ')
		set_color(&s[2], CF, data);
	else if (s[0] == 'C' && s[1] == ' ')
		set_color(&s[2], CC, data);
	else if (check_nullline(s))
	{
		free (s);
		return ;
	}
	else
		exit_this_way(O209"The data is not valid\n"RESET, false);
	free (s);
}

/*	
	check if the map is divided by no element line.
	check the player charactor(N or S or E or W, only 1 in thw map)
	and set the player direction
*/
void	check_map_elements(t_data *data, t_check_map *cm)
{
	t_mapline	*current;
	int			i;
	int			end;

	current = cm->begin;
	i = 0;
	end = 0;
	data->map->width = cm->maxcol;
	data->map->height = cm->maxline;
	while (current)
	{
		if (check_nullline(current->str) && end == 0)
			end = 1;
		if (check_nullline(current->str) == 0 && end == 1)
			exit_this_way(Y150"Map is divided\n"RESET, false);
		i = 0;
		while (current->str[i])
		{
			check_player_direction(current, data, i);
			i++;
		}
		current = current->next;
	}
	if (data->pos->dir == -1.0)
		exit_this_way(R199"No player in the map\n"RESET, false);
}

/*	
	check if the map data is valid with linked list,
	if valid, make mapdata(2d strings array) and clean the linked list.
	to check map data : "print_map_data(data);"
*/
bool	check_map_data(t_data *data, t_check_map *check_map_line)
{
	count_mapsize(check_map_line);
	check_map_elements(data, check_map_line);
	make_mapdata(data, check_map_line);
	check_wall(data);
	check_position(data);
	clear_mapline(check_map_line);
	return (true);
}
