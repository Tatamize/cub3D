/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhoukes <lhoukes@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 13:45:36 by lhoukes       #+#    #+#                 */
/*   Updated: 2023/01/22 14:48:04 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../header/data_set.h"

void	*protect_check(void *ptr)
{
	if (ptr == NULL)
		exit_this_way("Memory allocation failed", false);
	return (ptr);
}

int	exit_this_way(char *message, bool id)
{
	if (id == true)
	{
		ft_putstr_fd(message, 1);
		exit(0);
	}
	else if (id == false)
	{
		ft_putstr_fd(R160"ERROR\n"RESET, 1);
		ft_putstr_fd(message, 1);
		exit(1);
	}
	return (0);
}
