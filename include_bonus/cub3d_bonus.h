/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeberle <jeberle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 00:13:28 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/14 17:23:46 by jeberle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "./../libft/libft.h"
# include "./../mlx42/include/MLX42/MLX42.h"
# include "defs_bonus.h"
# include "structs_bonus.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>
# include <math.h>
# include <pthread.h>
# include <signal.h>

// audio
void			play_sound(pthread_t thread, void *(*play)(void *));
void			*door_open(void *arg);
void			*door_close(void *arg);
void			*bg_music(void *arg);

// ft_exit
void			call_exit_map(t_game *game);
void			call_exit(t_game *game);
int	is_door_open(t_game *game, int x, int y);

// ft_init
mlx_t			*ft_init_window(t_game *game);
t_map			*ft_initialize_map(char **map_in);
void			ft_initialize_game(t_game	*game);
void			ft_initialize(t_game *game, int argc, char **argv);
void			print_map_error(t_map *map, int ey, int ex);

// utils
char			get_cellchar(t_game *game, int x, int y);
void			check_collision(t_game *game, float *new_x, float *new_y);

// loop
void			my_keyhook(mlx_key_data_t keydata, void *param);
void			start_game(t_game *game);
int				draw_direction(t_game *game);
void			calc_delta(t_game *game, char operator);

// door_action
float			find_nearest_door(t_game *game, float *door_x, float *door_y);
void			toggle_door(t_game *game, int map_x, int map_y);

// load_textures_cub
int				ft_load_textures_minimap(t_game *game);

// map_content_check_spot.c
void			check_the_spot_down(t_map *map, int ydex, int xdex, int *err);
void			check_the_spot_up(t_map *map, int ydex, int xdex, int *err);
void			check_the_spot_left(t_map *map, int ydex, int xdex, int *err);
void			check_the_spot_right(t_map *map, int ydex, int xdex, int *err);
void			check_the_spot(t_map *map, int ydex, int xdex, int *err);

// map_content_flood.c
void			init_flood(t_map *map);
void			flood_one(char *ref, int *check, char *work);
int				check_xy_nexts(t_map *map, int ydex, int xdex);
void			flood(t_map *map);

// map_content_doors.c
void			check_doors(t_map *map, int *err);
t_door			*get_door(t_map *map, int x, int y);

// map_content_spawn.c
void			set_spawn_point(t_map *map, int x, int y);
void			handle_multiple_spawns(t_map *map, int y, int x, int *err);
void			check_spawn_cell(t_map *map, int y, int x, int *err);
void			handle_no_spawns(t_map *map, int *err);
void			check_spawn(t_map *map, int *err);

// map_content_validation
void			get_map_content(int fd, int *err, t_game *game);

// map_meta_helper
char			*get_textr_path(char *line, size_t size, int *err);
char			*trim_whitespace_and_newline(char *str);
uint32_t		create_color(int r, int g, int b);
int				validate_color_component(char *component);
int				validate_color_split(char **split);

// map_meta_parser
char			*trim_whitespace_and_newline(char *str);
char			*get_textr_path(char *line, size_t size, int *err);
uint32_t		parse_color(char *str, int start, int *err);
void			set_color_meta(int *err, char *line, t_game *g, char kind);
void			set_textr_meta(int *err, char *line, t_game *g, char ornttn);

// map_meta_validation
int				check_all_meta(t_game *game);
int				check_line_format(char *s1, size_t n);
int				got_meta_line(t_game *game, char *s1, char *s2, size_t n);
void			retreive_meta(char *line, int *err, t_game *game);
void			get_map_meta(int fd, int *qqqerr, t_game *game);

// map_validation
int				validate_map(t_game *game, char *filename);
int				validate_input(int argc, char **argv);
void			get_map(t_game *game, int argc, char **argv);

// map_parser_helper
void			find_map_width(char **splits, t_map_bounds *bounds);
char			*create_new_line(char *old_line, t_map_bounds *bounds);

// map_parser_rect
char			**allocate_result(size_t count);
int				alloc_and_cpy_line(char **result, t_splt_ctx *ctx, size_t len);
char			**allocate_rect_array(int num_rows);
char			**map_split(char *str);

// map_parser_trimmer
int				is_map_line(char *line);
void			find_map_bounds(char **splits, int *start, int *end);

// map_parser
size_t			count_lines(char *str);
char			**split_lines(char *str, size_t count);
void			free_splits(char **splits);
void			parse_map_array(t_map *map, char **splits);

// map_printers.c
void			ft_printmetas(t_map *map);
void			print_map(t_map *map);
void			print_map_error(t_map *map, int ey, int ex);

// load_textures_mini
int				ft_overlay(t_game *game);
int				ft_load_mini_char(t_game *game);
int				ft_load_minimap(t_game *game);
int				ft_load_map(t_game *game, char c, int color);
void			ft_set_color_minimap_char(mlx_image_t *image, uint32_t color);

// moves
int				check_move_up(t_game *game);
int				check_move_down(t_game *game);
int				check_move_left(t_game *game);
int				check_move_right(t_game *game);

// minimap
void			mclear_and_draw_frame(t_game *game);
void			mrender_rotmap(t_game *game, float cosa, float sina);
void			mdraw_rays(t_game *game, float cosa, float sina);
void			mdraw_player(t_game *game);
void			render_minimap(t_game *game);

// calculations
float			get_len_to_horizontal_wall(t_game *game, t_ray *ray);
float			get_len_to_vertical_wall(t_game *game, t_ray *ray);
int				ray_calculation(t_game *game);

// calculations directions
int				is_looking_right(float angle);
int				is_looking_down(float angle);
int				is_looking_left(float angle);
int				is_looking_up(float angle);

// calculations directions2
int				is_looking_north(float angle);
int				is_looking_east(float angle);
int				is_looking_south(float angle);
int				is_looking_west(float angle);

// calculations_utils
int				is_position_in_map(t_game *game, int pos_x, int pos_y);
int				is_wall(t_game *game, float x, float y);
int				get_h_drctn(float current_angle, float *y, float *len_y);
int				get_v_drctn(float current_angle, float *x, float *len_x);
float			calculate_len(t_game *game, float x, float y);
int				is_blocked(t_game *game, int x, int y);
// calculations_utils2
float			get_min(float a, float b);
float			angle_check(float angle);

// render
void			draw_ceiling(t_game *game, int index_of_ray, int top);
void			draw_floor(t_game *game, int index_of_ray, int bottom);
void			rendering_wall(t_game *game, t_ray ray);

// render utils
float			fish_eye_crct(t_game *game, float ray_len, float current_angle);
void			calc_wallslice_height(float *top, float *bottom);
void			drawpixel(mlx_image_t *image, float x, float y, uint32_t color);
int				ft_surface(t_game *game);
int				get_rgba_colors_hex(int red, int green, int blue, int alpha);

// render_wall
void			draw_wall(t_game *game, t_ray ray, int top, int bottom);

// render_wall_utils
int				get_pxl_clr(mlx_texture_t *texture, int x, int y);
mlx_texture_t	*get_texture(t_game *game, t_ray ray);
double			get_step_size(t_game *game, mlx_texture_t *texture, int height);
int				get_xpos(t_game *game, t_ray ray, mlx_texture_t *texture);

#endif
