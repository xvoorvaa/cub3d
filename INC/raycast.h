/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycast.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/14 13:50:40 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/06/14 19:09:19 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

typedef struct	t_pos
{
	double	x;
	double	y;
}	t_pos;


/*
	All raytracing data.
*/
typedef struct s_data
{
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				forward;
	int				backwards;
	int				left;
	int				right;
	int				rot_left;
	int				rot_right;
	t_pos			pos;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			camera_x;
	double			raydir_x;
	double			raydir_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	double			step_size;
	double			const_rad;
	double			wall_x;
	double			x_tex;
	double			y_tex;
	double			y_tex_step;
}	t_data;

#endif