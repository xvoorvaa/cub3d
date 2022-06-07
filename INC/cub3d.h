/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/13 21:22:16 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/06/07 17:36:44 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "MLX42/MLX42.h"
# include <stdbool.h>
# include <stddef.h>

# define SUCCES 0
# define ERROR 1

# define WIDTH 1280
# define HEIGHT 1024
# define MOVE_SPEED 1

typedef struct	s_node
{
	char 			*content;
	struct s_node	*next;
}	t_node;

typedef struct	s_textures
{
	mlx_image_t	*north_wall;
	mlx_image_t	*west_wall;
	mlx_image_t	*east_wall;
	mlx_image_t	*south_wall;
}	t_textures;

typedef struct	s_map
{
	char				**world_map;
	unsigned int		width;
	unsigned int		height;
}	t_map;

typedef struct s_data
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
}	t_data;


typedef struct	s_vars
{
	mlx_t		*mlx;
	t_map		map_data;
	t_textures	textures;
	t_data		data;
}	t_vars;

/*
	CUB3D
*/

int32_t			main(int argc, char *argv[]);

/*
	FILE CHECK
*/

bool			is_cub_file_valid(char *cub_file, t_vars *vars);

int				read_file(char *cub_file, t_vars *vars);

int				check_map(t_map *map_data);

/*
	UTILS
*/

int				get_next_line(int fd, char **line);

int				loop_through_line(char *map_line, char object);

bool			check_for_holes(t_map map_data);

/*
	WRAPPED
*/

int				ft_open(char *cub_file);

void			*ft_malloc(size_t size);

/*
	LINKED LIST
*/

void			new_node(t_node **head, char *content);

void			ft_free_list(t_node **head);

size_t			ft_lstlen(t_node *head);


/*
	CHECK_MAP
*/

int				check_player(t_map map_data);

int				check_wall(t_map map_data);

int				check_unknown(t_map map_data);

#endif
