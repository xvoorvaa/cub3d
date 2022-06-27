/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/14 17:58:30 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/06/27 14:57:33 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define NONVALID_FILE "-- Non valid extension. Need a .cub file! --"
# define ARGC_ERROR "-- I only need a .cub file --"
# define EMPTY_FILE "-- File is empty --"
# define GNL_ERROR "-- Something went wrong while reading .cub file --"
# define MISSING_WALL "-- Missing wall surrounding the map --"
# define MISSING_PLAYER "-- Missing player --"
# define TOO_MANY_PLAYERS "-- Too many players in the map --"
# define UNKNOWN_CHAR "-- Unknown character in map --"
# define NONVALID_MONITOR "-- Your monitor size is too small --"

/*
	ERROR
*/

void	non_fatal_error(char *msg);

void	fatal_perror(char *msg);

/*
	List of mallocs:
	1. get_lines
	2. 
*/

#endif
