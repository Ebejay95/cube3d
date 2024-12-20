/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:09:56 by ajehle            #+#    #+#             */
/*   Updated: 2024/10/17 17:23:27 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "cub3d.h"

typedef struct s_render_data
{
	int		x;
	int		y;
	int		map_x;
	int		map_y;
	float	rot_x;
	float	rot_y;
	float	cosa;
	float	sina;
}	t_render_data;

typedef struct s_split_context
{
	char	*str;
	size_t	count;
	size_t	i;
	size_t	j;
	char	*start;
}	t_splt_ctx;

typedef struct s_map_bounds
{
	int	start;
	int	end;
	int	left;
	int	right;
}	t_map_bounds;

typedef struct s_player
{
	float		x;
	float		y;
	float		angle;
}	t_player;

typedef struct s_key_states {
	bool	w_pressed;
	bool	s_pressed;
	bool	a_pressed;
	bool	d_pressed;
	bool	left_pressed;
	bool	right_pressed;
	bool	up_pressed;
}	t_key_states;

typedef struct s_map
{
	char			**content;
	mlx_texture_t	*tex_west;
	mlx_texture_t	*tex_east;
	mlx_texture_t	*tex_north;
	mlx_texture_t	*tex_south;
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

typedef struct s_game
{
	t_map			*map;
	mlx_t			*mlx;
	mlx_image_t		*surface;
	t_player		*player;
	t_key_states	key_states;
	int				mouse_locked;
	int				frame_bonus;
	float			deltax;
	float			deltay;
	float			angle;
}					t_game;

typedef struct s_ray
{
	int		index;
	float	current_angle;
	float	horizontal_len;
	float	vertical_len;
	float	len;
	float	wall_hit_y;
	float	wall_hit_x;
}	t_ray;

#endif
