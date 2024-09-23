/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:14:01 by ajehle            #+#    #+#             */
/*   Updated: 2024/09/23 08:59:04 by jeberle          ###   ########.fr       */
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

void		call_exit_minimap(t_mini *minimap);
void		call_exit_map(t_game *game);
void		call_exit(t_game *game);

// ft_init
mlx_t		*ft_init_window(t_game *game);
t_mini*		ft_initialize_minimap(void);
t_map		*ft_initialize_map(char** map_in);
t_game		*ft_initialize_game(void);
t_game* 	ft_initialize(int argc, char **argv);


// utils
void		print_2d_arr(char **map_in_arr);

// loop
void		my_keyhook(mlx_key_data_t keydata, void *param);
void		start_game(t_game *game);

// load_textures_cub
int			ft_load_textures_minimap(t_game *game);

// map_content_validation
void		get_map_content(int fd, int *err, t_game *game);

// map_meta_parser
char		*get_textr_path(char *line, size_t size, int *err);
uint32_t	parse_color(char *str, int start, int *err);
void		set_color_meta(int *err, char *line, t_game *g, char kind);
void		set_textr_meta(int *err, char *line, t_game *g, char ornttn);

// map_meta_validation
int			check_all_meta(t_game *game);
int			check_line_format(const char *s1, size_t n);
int			got_meta_line(t_game *game, const char *s1, const char *s2, size_t n);
void		retreive_meta(char *line, int *err, t_game *game);
void		get_map_meta(int fd, int *err, t_game *game);

// map_validation
int			validate_map(t_game *game, char *filename);
int			validate_input(int argc, char **argv);
void		get_map(t_game *game, int argc, char **argv);

// map_parser_rect
char			**allocate_result(size_t count);
int				allocate_and_copy_line(char **result, size_t j, const char *start, size_t len);
char			**allocate_rect_array(int num_rows);
char			**map_split(const char *str);
int				fill_rect_array(char **rect_array, char **splits, int max_len, int num_rows);

// map_parser
size_t			count_lines(const char *str);
char			**split_lines(const char *str, size_t count);
void			get_map_dimensions(char **splits, int *max_len, int *num_rows);
void			free_splits(char **splits);
char			**parse_map_array(char **splits);

// load_textures_mini
int			ft_overlay(t_game* game);
int			ft_load_mini_char(t_game *game);
int			ft_load_minimap(t_game *game);
int			ft_load_map(t_game *game, char c, int color);
void		ft_set_color_minimap_char(mlx_image_t *image, uint32_t color);

// textures
int			load_textures(t_game *game);

#endif
