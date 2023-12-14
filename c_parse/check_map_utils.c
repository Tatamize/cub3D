/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_map_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhoukes <lhoukes@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 17:47:58 by lhoukes       #+#    #+#                 */
/*   Updated: 2023/01/22 14:57:59 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "../libft/libft.h"
#include "../header/data_set.h"

bool	ft_white_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\v' || c == '\f' \
		|| c == '\n' || c == '\r')
		return (true);
	return (false);
}

char	*ft_skip_white_space(char *line)
{
	while (ft_white_space(*line))
		line++;
	return (line);
}

bool	check_nullline(char *s)
{
	int	i;

	i = 0;
	while (ft_white_space(s[i]))
		i++;
	if (s[i] == '\n' || s[i] == '\0')
		return (true);
	return (false);
}

void	count_mapsize(t_check_map *check_map_line)
{
	int			max;
	int			line;
	int			temp;
	t_mapline	*current;

	max = 0;
	line = 0;
	temp = 0;
	current = check_map_line->begin;
	while (current)
	{
		temp = ft_strlen(current->str);
		if (max < temp)
			max = temp;
		current = current->next;
		line++;
	}
	check_map_line->maxcol = max;
	check_map_line->maxline = line;
	if (check_map_line->maxcol == 0 && check_map_line->maxline == 0)
		exit_this_way("Map is empty\n", false);
	if (check_map_line->maxcol < 3 || check_map_line->maxline < 3)
		exit_this_way("Map is to small for cub3D\n", false);
}
