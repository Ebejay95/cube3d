/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:14:01 by ajehle            #+#    #+#             */
/*   Updated: 2024/09/19 15:31:42 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./../libft/libft.h"
# include "./../mlx42/include/MLX42/MLX42.h"
# include "defs.h"
# include "structs.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>
# include <math.h>


// ft_exit

void	call_exit_minimap(t_mini *minimap);
void	call_exit_map(t_map *map);
void	call_exit(t_game *game);

// ft_init
mlx_t	*ft_init_window(t_game *game);
t_mini*	ft_initialize_minimap(void);
t_map	*ft_initialize_map(char** map_in);
t_game	*ft_initialize_game(void);
t_game* ft_initialize(t_map	*map_as_string);


// utils
void	print_2d_arr(char **map_in_arr);

// loop
void	my_keyhook(mlx_key_data_t keydata, void *param);
void	start_game(t_game *game);

// load_textures_cub
int		ft_load_textures_minimap(t_game *game);

// map_validation
t_map	*get_map(int argc, char **argv);

// load_textures_mini
int		ft_overlay(t_game* game);
int		ft_load_mini_char(t_game *game);
int		ft_load_minimap(t_game *game);
int		ft_load_map(t_game *game, char c, int color);
void	ft_set_color_minimap_char(mlx_image_t *image, uint32_t color);

// textures
int		load_textures(t_game *game);

#endif
