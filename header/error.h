/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhoukes <lhoukes@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 13:43:24 by lhoukes       #+#    #+#                 */
/*   Updated: 2023/01/20 08:44:41 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# include <stdbool.h>

void	*protect_check(void *ptr);
int		exit_this_way(char *message, bool id);

#endif