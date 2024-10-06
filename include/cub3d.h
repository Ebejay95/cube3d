/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:14:01 by ajehle            #+#    #+#             */
/*   Updated: 2024/10/06 17:10:57 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

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
void		call_exit_map(t_game *game);
void		call_exit(t_game *game);

// ft_init
mlx_t		*ft_init_window(t_game *game);
t_map		*ft_initialize_map(char **map_in);
void		ft_initialize_game(t_game	*game);
void		ft_initialize(t_game *game, int argc, char **argv);
void		print_map_error(t_map *map, int ey, int ex);

// utils
char		get_cellchar(t_game *game, int x, int y);
void		check_collision(t_game *game, float *new_x, float *new_y);

// loop
void		my_keyhook(mlx_key_data_t keydata, void *param);
void		start_game(t_game *game);
int			draw_direction(t_game *game);
void		calc_delta(t_game *game, char operator);

// load_textures_cub
int			ft_load_textures_minimap(t_game *game);

// map_content_check_spot.c
void		check_the_spot_down(t_map *map, int ydex, int xdex, int *err);
void		check_the_spot_up(t_map *map, int ydex, int xdex, int *err);
void		check_the_spot_left(t_map *map, int ydex, int xdex, int *err);
void		check_the_spot_right(t_map *map, int ydex, int xdex, int *err);
void		check_the_spot(t_map *map, int ydex, int xdex, int *err);

// map_content_flood.c
void		init_flood(t_map *map);
void		flood_one(char *ref, int *check, char *work);
int			check_xy_nexts(t_map *map, int ydex, int xdex);
void		flood(t_map *map);

// map_content_spawn.c
void		set_spawn_point(t_map *map, int x, int y);
void		handle_multiple_spawns(t_map *map, int y, int x, int *err);
void		check_spawn_cell(t_map *map, int y, int x, int *err);
void		handle_no_spawns(t_map *map, int *err);
void		check_spawn(t_map *map, int *err);

// map_content_validation
void		get_map_content(int fd, int *err, t_game *game);

// map_meta_parser
char		*get_textr_path(char *line, size_t size, int *err);
uint32_t	parse_color(char *str, int start, int *err);
void		set_color_meta(int *err, char *line, t_game *g, char kind);
void		set_textr_meta(int *err, char *line, t_game *g, char ornttn);

// map_meta_validation
int			check_all_meta(t_game *game);
int			check_line_format(char *s1, size_t n);
int			got_meta_line(t_game *game, char *s1, char *s2, size_t n);
void		retreive_meta(char *line, int *err, t_game *game);
void		get_map_meta(int fd, int *qqqerr, t_game *game);

// map_validation
int			validate_map(t_game *game, char *filename);
int			validate_input(int argc, char **argv);
void		get_map(t_game *game, int argc, char **argv);

// map_parser_rect
char		**allocate_result(size_t count);
int			alloc_and_cpy_line(char **result, t_split_context *ctx, size_t len);
char		**allocate_rect_array(int num_rows);
char		**map_split(char *str);

// map_parser_trimmer
int			is_map_line(char *line);
void		find_map_bounds(char **splits, int *start, int *end);

// map_parser
size_t		count_lines(char *str);
char		**split_lines(char *str, size_t count);
void		free_splits(char **splits);
void		parse_map_array(t_map *map, char **splits);

// map_printers.c
void		ft_printmetas(t_map *map);
void		print_map(t_map *map);
void		print_map_error(t_map *map, int ey, int ex);

// load_textures_mini
int			ft_overlay(t_game *game);
int			ft_load_mini_char(t_game *game);
int			ft_load_minimap(t_game *game);
int			ft_load_map(t_game *game, char c, int color);
void		ft_set_color_minimap_char(mlx_image_t *image, uint32_t color);

// textures
int			load_textures(t_game *game);

// moves
int			check_move_up(t_game *game);
int			check_move_down(t_game *game);
int			check_move_left(t_game *game);
int			check_move_right(t_game *game);


// minimap
void mclear_and_draw_frame(t_game *game);
void mrender_rotated_map(t_game *game, float cos_angle, float sin_angle);
void mdraw_rays(t_game *game, float cos_angle, float sin_angle);
void mdraw_player(t_game *game);
void render_minimap(t_game *game);

// calculations
float	get_len_to_horizontal_wall(t_game* game, float current_angle);
float	get_len_to_vertical_wall(t_game* game, float current_angle);
int		ray_calculation(t_game* game);

// calculations directions
int is_looking_right(float angle);
int is_looking_down(float angle);
int is_looking_left(float angle);
int is_looking_up(float angle);

// calculations directions2
int is_looking_south(float angle);
int is_looking_west(float angle);

// calculations_utils
int		is_position_in_map(t_game* game,int pos_x,int pos_y);
int		is_wall(t_game* game,float x_coordinate,float y_coordinate);
int		get_horizontal_direction(float current_angle,float* y_coordinate,float* len_y);
int		get_vertical_direction(float current_angle,float* x_coordinate,float* len_x);
float	calculate_len(t_game* game,float x_coordinate,float y_coordinate);

// calculations_utils2
float	get_min(float a, float b);
float	angle_check(float angle);

// render
void	draw_ceiling(mlx_image_t *surface,int index_of_ray ,int top);
void	draw_floor(mlx_image_t *surface,int index_of_ray ,int bottom);
void	rendering_wall(t_game* game, t_ray ray);

// render utils
float	fish_eye_correction(t_game* game, float ray_len, float current_angle);
void	calculate_wall_slice_height(float height, float *top, float *bottom);
void	draw_pixel(mlx_image_t *image, float x, float y, uint32_t color);
int		ft_surface(t_game *game);
int		get_rgba_colors_hex(int red, int green, int blue, int alpha);


#endif
