/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:14:01 by ajehle            #+#    #+#             */
/*   Updated: 2024/09/19 09:05:10 by ajehle           ###   ########.fr       */
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

void	call_exit_minimap(t_mini *minimap);
void	call_exit_map(t_map *map);
void	call_exit(t_game *game);

// ft_init
mlx_t	*ft_init_window(t_game *game);
t_mini*	ft_initialize_minimap(void);
t_map	*ft_initialize_map(char* map_as_string);
t_game	*ft_initialize_game(void);
t_game* ft_initialize(char* map_as_string);



// utils
void	print_2d_arr(char **map_in_arr);

// loop
void	my_keyhook(mlx_key_data_t keydata, void *param);
void	start_game(t_game *game);





#endif
