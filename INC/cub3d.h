/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/13 21:22:16 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/07/17 13:37:49 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "MLX42/MLX42.h"
# include "libft.h"
# include "raycast.h"

# include <stdbool.h>
# include <stddef.h>

# define SUCCES 0
# define ERROR 1

# define WIDTH 1000
# define HEIGHT 800

# define UINT unsigned int

/*
	Needed to get the file lines.
*/
typedef struct s_node
{
	struct s_node	*next;
	char			*content;
}	t_node;

/*
	Textures of walls will be saved here from PNG to texture.
	The whole screen as well.
*/
typedef struct s_textures
{
	mlx_texture_t	*north_wall;
	mlx_texture_t	*west_wall;
	mlx_texture_t	*east_wall;
	mlx_texture_t	*south_wall;
	mlx_image_t		*screen;
}	t_textures;

/*
	All the path vars from file.
*/
typedef struct s_path
{
	char		*north;
	char		*south;
	char		*east;
	char		*west;
}	t_path;

/*
	RGB colors for floor/ceilling.
*/
typedef struct s_colors
{
	char		*floor;
	char		*ceilling;
	int			*RGB[3];
}	t_colors;

/*
	All the map data in one struct.
*/
typedef struct s_map
{
	char			**world_map;
	unsigned int	map_start;
	unsigned int	width;
	unsigned int	height;
}	t_map;

/*
	All data, like map data, raycasting data, MLX & textures.
*/
typedef struct s_vars
{
	mlx_t		*mlx;
	t_map		map_data;
	t_path		path_data;
	t_textures	textures;
	t_colors	colors;
	t_data		data;
}	t_vars;

/*
	CUB3D
*/

int32_t	main(int argc, char *argv[]);

void	raycasting_hook(void *param);

void	draw_hook(void *param);

/*
	FILE CHECK
*/

bool	is_cub_file_valid(char *cub_file, t_vars *vars);

int		read_file(char *cub_file, t_vars *vars);

int		check_map(t_map *map_data);

/*
	UTILS
*/

int		get_next_line(int fd, char **line);

int		loop_through_line(char *map_line, char object);

bool	check_for_holes(char *world_map[]);

void	find_player(t_vars *vars);

bool	is_monitor_valid(mlx_t *mlx);

/*
	WRAPPED
*/

int		ft_open(char *cub_file);

/*
	LINKED LIST
*/

void	new_node(t_node **head, char *content);

void	ft_free_list(t_node **head);

size_t	ft_lstlen(t_node *head);

/*
	CHECK_MAP
*/

int		check_player(t_map map_data);

int		check_wall(t_map *map_data);

int		check_unknown(t_map map_data);

bool	is_wall_enclosed(char *world_map[]);

/*
	MOVEMENT
*/

void	movement_hook(void *param);

void	rotate(t_data *s, double turn);

/*
	DRAW
*/

void	draw_wall(t_data *data, mlx_image_t *screen, \
	mlx_texture_t *texture, UINT x);

void	reset_window(mlx_image_t *screen);

void	draw_floor(mlx_image_t *screen, int draw_end, uint32_t colour, int x);

void	draw_ceiling(mlx_image_t *screen, int draw_start, \
	uint32_t colour, int x);

/*
	RAYCASTING
*/

void	set_delta_dist(t_data *data);

/*
	MY_MLX
*/

UINT	my_mlx_get_colour(mlx_texture_t *img, UINT x, UINT y);

UINT	my_mlx_put_pixel(mlx_image_t *img, UINT x, UINT y, UINT colour);

void	my_mlx_resize_window(mlx_t *mlx, t_data *data, mlx_image_t *screen);

#endif
