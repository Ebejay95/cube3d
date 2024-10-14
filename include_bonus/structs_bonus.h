/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 00:12:20 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/14 22:28:41 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_BONUS_H
# define STRUCTS_BONUS_H

# include "cub3d_bonus.h"
# include <pthread.h>

typedef struct s_hit {
	float	distance;
	int		is_door;
	float	x;
	float	y;
}	t_hit;

typedef struct s_door_finder
{
	float	min_distance;
	float	door_x;
	float	door_y;
	int		found;
}	t_door_finder;

typedef struct s_dctx
{
	float	x;
	float	y;
	float	angle;
	float	distance;
	float	sin_a;
	float	cos_a;
	int		map_x;
	int		map_y;
	char	cell;
}	t_dctx;

typedef struct s_door
{
	int		x;
	int		y;
	int		open;
	char	direction;
}	t_door;

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

typedef struct s_ray_data {
	float	x;
	float	y;
	float	len_x;
	float	len_y;
	int		direction;
	int		map_x;
	int		map_y;
}	t_ray_data;

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
	bool	space_pressed;
}	t_key_states;

typedef struct s_map
{
	char			**content;
	mlx_texture_t	*tex_west;
	mlx_texture_t	*tex_east;
	mlx_texture_t	*tex_north;
	mlx_texture_t	*tex_south;
	mlx_texture_t	*tex_door;
	mlx_image_t		hand_one;
	mlx_image_t		hand_two;
	mlx_image_t		hand_three;
	mlx_image_t		hand_four;
	mlx_image_t		hand_five;
	mlx_image_t		hand_six;
	uint32_t		ceiling;
	uint32_t		floor;
	int				ceiling_set;
	int				floor_set;
	int				width;
	int				height;
	int				spawn_x;
	int				spawn_y;
	char			spawn;
	t_door			*doors[MAX_DOORS];
	int				door_count;
}					t_map;

typedef struct s_game
{
	t_map				*map;
	mlx_t				*mlx;
	mlx_image_t			*surface;
	t_player			*player;
	t_key_states		key_states;
	int					mouse_locked;
	int					frame_bonus;
	float				deltax;
	float				deltay;
	float				angle;
	pthread_t			music_thread;
	pthread_t			door_open_thread;
	pthread_t			door_close_thread;
	int					run_music;
	int					bg_sec;
	pid_t				music_pid;
	const mlx_image_t	hand_images[6];
	int					current_hand_frame;
	bool				animating_hand;
	bool				is_pressed;
}						t_game;

typedef struct s_optimization
{
	int		ray_step;
	float	max_distance;
}	t_optimization;

typedef struct s_ray
{
	int		index;
	float	current_angle;
	float	horlen;
	float	verlen;
	float	len;
	float	wall_hit_y;
	float	wall_hit_x;
	int		hit_door;
}	t_ray;

typedef struct s_wall_data {
	t_game			*game;
	t_ray			ray;
	int				top;
	int				bottom;
	mlx_texture_t	*texture;
	int				tex_x;
}	t_wall_data;

#endif
