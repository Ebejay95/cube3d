/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:14:01 by ajehle            #+#    #+#             */
/*   Updated: 2024/09/14 12:17:46 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libs/ft_printf/include/ft_printf.h"
# include "../libs/get_next_line/get_next_line.h"
# include "../libs/libft/include/libft.h"
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
void	ft_exit_pos(t_pos *pos);
void	ft_exit_delta(t_delta *delta);
void	ft_exit_minimap(t_mini *minimap);
void	call_exit_map(t_map *map);
void	call_exit(t_game *game);

// ft_init
t_mini	*ft_initialize_minimap(t_map* map);
t_game	*ft_initialize_game(t_map *map, t_mini* mini);
t_map	*ft_initialize_map(char* string);
t_mini	*ft_initialize_mini(void);
mlx_t	*ft_init_window(t_game *game);
t_game	*ft_init(t_map *map, t_mini* mini);
int	start_minimap(t_game *game, t_map *map);


// utils
void	print_2d_arr(char **map_in_arr);
t_pos	*get_pos_unique(char **map_as_arr, char c);




#endif
