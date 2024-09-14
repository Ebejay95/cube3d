/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:09:56 by ajehle            #+#    #+#             */
/*   Updated: 2024/09/14 11:55:04 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "cub3d.h"

typedef struct s_pos
{
	int			x;
	int			y;
}					t_pos;

typedef struct s_delta
{
	float		x;
	float		y;
	float		a;
}					t_delta;

typedef struct s_map
{
	char*			map_as_string;
	char**			map_as_arr;
	int				width;
	int				height;
}					t_map;

typedef struct s_mini
{
	mlx_image_t*	image;
	mlx_image_t*	img_dir;
	mlx_image_t*	overlay;
	t_pos*			pos;
	t_delta*		delta;
}					t_mini;


typedef struct s_game
{
	t_map*			map;
	t_mini*			minimap;
	mlx_t*			game_mlx;
	int				frame;
}					t_game;

#endif
