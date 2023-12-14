/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhoukes <lhoukes@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 14:07:11 by lhoukes       #+#    #+#                 */
/*   Updated: 2023/01/20 12:54:32 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include "../header/data_set.h"
#include "../header/parse.h"

/* 	
	checks for the right exe
	and sets the offset for the compair
	function returns true if it is right extension
*/
bool	is_correct_ext(char *argument, char *extension)
{
	int				length;
	int				offset;
	unsigned int	to_check;

	to_check = 0;
	length = ft_strlen(argument);
	offset = length - 4;
	while (to_check <= 4 && offset < length)
	{
		if (argument[offset] != extension[to_check])
			return (false);
		to_check++;
		offset++;
	}
	return (true);
}

/* 	
	cub3D needs 2 arg to continue
	the 2nd arg (arg[1]) need to be a .cub
	returns true if both are correct
*/
bool	are_correct_args(int argc, char **argv)
{
	if (argc == 2)
	{
		if (is_correct_ext(argv[1], ".cub") == false)
			exit_this_way(Y151"Not the right extension for map\n"RESET, false);
	}
	else
		return (false);
	return (true);
}

/* 
	opens the .cub file and reads line by line GNL returns 1 for a line, 
	0 for end of file & -1 if we can't read from file. 
	As long as this goes well, resources are check, and map is made (and checked).
*/
bool	check_data(const char *file, t_data *data)
{
	int			fd;
	char		*str;
	int			gnl;
	t_check_map	cm;

	init_cmap(&cm);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_this_way(strerror(errno), false);
	str = NULL;
	gnl = 1;
	while (gnl > 0)
	{
		gnl = get_next_line(fd, &str);
		if (gnl == -1)
			exit_this_way(R201"This is not a file\n"RESET, false);
		if (!resource_ready(data))
			check_resource(str, data);
		else
			get_mapline(str, &cm);
	}
	close(fd);
	check_map_data(data, &cm);
	return (true);
}
