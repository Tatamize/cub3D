/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhoukes <lhoukes@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 12:32:21 by lhoukes       #+#    #+#                 */
/*   Updated: 2023/01/22 13:55:50 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header/data_set.h"
#include "header/parse.h"
#include "header/canvas.h"

/*	
	to check data : print_data(&data);
	to check leak : system("leaks -q cub3D");
*/
int	main(int argc, char **argv)
{
	t_data	data;

	if (are_correct_args(argc, argv) == false)
		exit_this_way(R199"Not the right arguments to run cub3D\n" \
			RESET, false);
	init_data(&data);
	if (!check_data(argv[1], &data))
		exit_this_way(P57"The .cub file is not correct\n"RESET, false);
	make_canvas(&data);
	clean_up(&data);
	mlx_terminate(data.canvas->canv);
	return (0);
}
