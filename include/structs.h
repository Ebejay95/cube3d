/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:09:56 by ajehle            #+#    #+#             */
/*   Updated: 2024/09/24 14:13:05 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "cub3d.h"

typedef struct s_player
{
	int		x;
	int		y;
	double	angle;
}	t_player;

typedef struct s_map
{
	char**			content;
	mlx_texture_t	*tex_west;
	mlx_image_t		*img_west;
	mlx_texture_t	*tex_east;
	mlx_image_t		*img_east;
	mlx_texture_t	*tex_north;
	mlx_image_t		*img_north;
	mlx_texture_t	*tex_south;
	mlx_image_t		*img_south;
	uint32_t		ceiling;
	uint32_t		floor;
	int				ceiling_set;
	int				floor_set;
	int				width;
	int				height;
	int				spawn_x;
	int				spawn_y;
	char			spawn;
}					t_map;

typedef struct s_mini
{
	mlx_image_t*	player;
	mlx_image_t*	plyr_dir;
	mlx_image_t*	overlay;
	int				px_width;
	int				px_height;
	int				map_width;
	int				map_height;
	int				pos_x;
	int				pos_y;
	float			delta_x;
	float			delta_y;
	float			angle;
}					t_mini;


typedef struct s_game
{
	t_map*			map;
	t_mini*			minimap;
	mlx_t*			mlx;
	t_player		*player;
}					t_game;

#endif
