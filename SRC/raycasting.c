/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/07 19:27:12 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/06/09 18:28:12 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



void	raycasting_hook(void *param)
{
	int		x;
	t_vars	*vars;

	x = 0;
	vars = param;
	while (x < WIDTH)
	{
		cast_ray(vars->data[i]);
		i++;
	}
}