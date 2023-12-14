/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhoukes <lhoukes@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 14:08:48 by lhoukes       #+#    #+#                 */
/*   Updated: 2023/01/22 13:39:40 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include <stdbool.h>
# include "../libft/libft.h"
# include "data_set.h"

/*get next line functions*/
int		get_next_line(int fd, char **line);
char	*create_line(char *line1, char *line2);
int		check_read(char *buff_line, int fd);
int		check_line_length(char *line, char to_find);
int		compair_and_copy(char *line1, char *line2, char to_find);
int		move_and_join(char **line, char *buff_line);

/*parse functions*/
bool	are_correct_args(int argc, char **argv);
bool	check_nullline(char *s);
bool	check_data(const char *file, t_data *data);
void	check_resource(char *s, t_data *data);
void	get_mapline(char *s, t_check_map *cm);
void	set_texture_data(char *s, int type, t_data *data);
void	set_color(char *s, int type, t_data *data);
void	print_data(t_data *data);
void	print_map_data(t_data *data);
bool	check_map_data(t_data *data, t_check_map *cm);
char	*ft_skip_white_space(char *line);
bool	ft_white_space(char c);

#endif
