/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_and_set_color.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhoukes <lhoukes@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/13 18:11:08 by lhoukes       #+#    #+#                 */
/*   Updated: 2023/01/23 10:15:44 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header/data_set.h"
#include "../header/parse.h"

/* 
	get the color info from offset start point,
	return the number until next commma (or end of string) 
*/
int	get_color_info(int *color, char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ')
		i++;
	*color = ft_atoui(&s[i]);
	if (*color < 0 && s[i] == ',')
		*color = 0;
	while (s[i] != ',' && s[i] != '\0' && s[i] != ' ')
	{
		if (s[i] < 48 || s[i] > 57)
			exit_this_way("Color is invalid\n", false);
		i++;
	}
	if (*color < 0 || *color > 255)
		exit_this_way("Color is invalid\n", false);
	return (i);
}

/* 
	count how many commas in the string(2 is valid), and check invalid charactor.
*/
void	check_comma_num(char *s)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	while (s[i])
	{
		if (s[i] == ',')
			comma++;
		if (s[i] != ',' && s[i] != ' ' && (s[i] < 48 || s[i] > 57))
			exit_this_way("Color information is wrong!\n", false);
		i++;
	}
	if (comma != 2)
		exit_this_way("Color information is not enough or too much\n", false);
}

/* 
	check inside the string (2 commmas, spaces or numbers are valid).
	i is offset during getting color info, it indicates next comma.
*/
void	set_color(char *s, int type, t_data *data)
{
	int	i;
	int	r;
	int	g;
	int	b;

	check_comma_num(s);
	i = get_color_info(&r, s);
	if (r < 0)
		exit_this_way(R196"Color r is invalid\n"RESET, false);
	while (s[i] == ',' || s[i] == ' ')
		i++;
	i += get_color_info(&g, &s[i]);
	if (g < 0)
		exit_this_way(G42"Color g is invalid\n"RESET, false);
	while (s[i] == ',' || s[i] == ' ')
		i++;
	i += get_color_info(&b, &s[i]);
	if (b < 0)
		exit_this_way(B31"Color b is invalid\n"RESET, false);
	if (type == CF && data->deco->color_f == 0)
		data->deco->color_f = (r << 24 | g << 16 | b << 8 | 255);
	else if (type == CC && data->deco->color_c == 0)
		data->deco->color_c = (r << 24 | g << 16 | b << 8 | 255);
	else
		exit_this_way("Color data is already set\n", false);
}
