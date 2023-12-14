/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_map_list.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhoukes <lhoukes@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 17:47:25 by lhoukes       #+#    #+#                 */
/*   Updated: 2023/01/20 15:05:46 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header/data_set.h"
#include "../header/parse.h"

/* 
	make a linked list containing per node a map_line
*/
void	get_mapline(char *str, t_check_map *check_map_line)
{
	t_mapline	*map_line;

	map_line = NULL;
	if (check_nullline(str) && check_map_line->begin == NULL)
	{
		free (str);
		return ;
	}
	map_line = protect_check(malloc(sizeof(t_mapline) * 1));
	map_line->str = str;
	map_line->next = NULL;
	if (check_map_line->begin == NULL)
	{
		check_map_line->begin = map_line;
		check_map_line->last = map_line;
	}	
	else
	{
		check_map_line->last->next = map_line;
		check_map_line->last = map_line;
	}
}

/*	
	clear linked list after use
*/
void	clear_mapline(t_check_map *check_map_line)
{
	t_mapline	*current;
	t_mapline	*temp;

	temp = NULL;
	current = check_map_line->begin;
	while (current)
	{
		temp = current;
		free(current->str);
		current = current->next;
		free(temp);
	}
}
