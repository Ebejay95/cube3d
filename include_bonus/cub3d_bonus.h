/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 00:13:28 by jeberle           #+#    #+#             */
/*   Updated: 2024/10/29 11:38:02 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "./../libft/libft.h"
# include "./../mlx42/include/MLX42/MLX42.h"
# include "defs_bonus.h"
# include "structs_bonus.h"
# include <fcntl.h>
# include <math.h>
# include <pthread.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>

// minimap_bonus
void			calculate_map_coordinates(t_game *game, t_render_data *d);
int				is_valid_map_position(t_game *game, t_render_data *d);
void			mdraw_player(t_game *game);
void			render_minimap(t_game *game);

// minimap_bonus2
void			handle_door(t_game *game, t_render_data *d);
void			handle_room(t_game *game, t_render_data *d);
void			process_map_content(t_game *game, t_render_data *d);
void			process_column(t_game *game, t_render_data *d);
void			mrender_rotmap(t_game *game, float cosa, float sina);

// minimap_bonus3
void			handle_wall(t_game *game, t_render_data *d);

// map_content_check_spot
void			check_the_spot_down(t_map *map, int ydex, int xdex, int *err);
void			check_the_spot_up(t_map *map, int ydex, int xdex, int *err);
void			check_the_spot_left(t_map *map, int ydex, int xdex, int *err);
void			check_the_spot_right(t_map *map, int ydex, int xdex, int *err);
void			check_the_spot(t_map *map, int ydex, int xdex, int *err);

// map_content_doors
void			check_doors(t_map *map, int *err);
t_door			*get_door(t_map *map, int x, int y);
void			check_door_cell(t_map *map, int y, int x, int *err);
void			add_door(t_map *map, int x, int y, int *err);
void			get_door_direction(t_map *m, int x, int y, char *dir);

// map_content_flood_bonus
void			init_flood(t_map *map);
void			flood_one(char *ref, int *check, char *work);
int				check_xy_nexts(t_map *map, int ydex, int xdex);
void			flood(t_map *map);

// map_content_spawn_bonus
void			set_spawn_point(t_map *map, int x, int y);
void			handle_multiple_spawns(t_map *map, int y, int x, int *err);
void			check_spawn_cell(t_map *map, int y, int x, int *err);
void			handle_no_spawns(t_map *map, int *err);
void			check_spawn(t_map *map, int *err);

// map_content_validation_bonus2
void			check_chars(t_map *map, int *err);
int				has_defined_insides(t_map *map);
void			map_validation(t_map *map, int *err);
void			handle_clear_spawn_point(t_map *m, int x, int y);
void			handle_clear_x_content(t_map *m, int x, int y);

// map_content_validation_bonus3
void			handle_clear_door(t_map *m, int x, int y, int dx);

// map_content_validations_bonus
void			process_clear_doors(t_map *m, int x, int y);
void			process_clear_cell(t_map *m, int x, int y);
void			process_clear_row(t_map *m, int y);
void			clear_validation(t_map *m);
void			get_map_content(int fd, int *err, t_game *game);

// map_meta_helper_bonus
char			*get_textr_path(char *line, size_t size, int *err);
char			*trim_whitespace_and_newline(char *str);
uint32_t		create_color(int r, int g, int b);
int				validate_color_component(char *component);
int				validate_color_split(char **split);

// map_meta_parser_bonus
char			**split_and_trim(char *str, char s);
uint32_t		parse_color(char *str, int start, int *err);
void			set_color_meta(int *err, char *line, t_game *g, char kind);
void			set_textr_meta(int *err, char *line, t_game *g, char ornttn);

// map_meta_validations_bonus
int				check_all_meta(t_game *game);
int				got_meta_line(t_game *game, char *s1, char *s2, size_t n);
void			retreive_meta(char *line, int *err, t_game *game);
void			get_map_meta(int fd, int *err, t_game *game);

// map_parser_bonus
void			trim_map_content(char **splits, t_map_bounds *bounds);
int				allocate_map_content(t_map *map);
int				copy_map_content_process(t_map *map, char **splits, int start,
					int i);
int				copy_map_content(t_map *map, char **splits, int start);
void			parse_map_array(t_map *map, char **splits);

// map_parser_helper_bonus
size_t			count_lines(char *str);
int				alloc_and_cpy_line(char **result, t_splt_ctx *ctx, size_t len);
char			**split_lines_init(size_t count);
char			**split_lines_process(char **result, t_splt_ctx *ctx);
char			**split_lines(char *str, size_t count);

// map_parser_helper2_bonus
void			free_splits(char **splits);
void			update_map_bounds(char c, t_map_bounds *bounds, int j);
void			find_map_width_init(t_map_bounds *bounds);
void			find_map_width_process(char **splits, int i,
					t_map_bounds *bounds);
void			find_map_width(char **splits, t_map_bounds *bounds);

// map_parser_helper3_bonus
char			*create_new_line(char *old_line, t_map_bounds *bounds);

// map_parser_rect_bonus
char			**allocate_result(size_t count);
char			**allocate_rect_array(int num_rows);
char			**map_split(char *str);

// map_parser_trimmer_bonus
int				is_map_line(char *line);
void			find_map_bounds(char **splits, int *start, int *end);

// map_parser
void			trim_map_content(char **splits, t_map_bounds *bounds);
int				allocate_map_content(t_map *map);
int				copy_map_content_process(t_map *map, char **splits, int start,
					int i);
int				copy_map_content(t_map *map, char **splits, int start);
void			parse_map_array(t_map *map, char **splits);

// map_printers_bonus
void			ft_printmetas(t_map *map);
void			print_map(t_map *map);
void			print_map_error(t_map *map, int ey, int ex);

// map_validation_bonus
int				validate_map(t_game *game, char *filename);
int				validate_input(int argc, char **argv);
void			setup_game_stuff(t_game *game);
void			get_map(t_game *game, int argc, char **argv);

// calculations_bonus
void			init_ray_info(t_ray_info *info, t_game *game, float angle,
					int is_hor);
int				is_hit(t_game *game, t_ray_info *info);
t_hit			cast_ray(t_game *game, float angle, int is_horizontal);
float			get_len_to_wall(t_game *game, t_ray *ray);
int				ray_calculation(t_game *game);

// calculations_bonus2
void			update_map_coordinates(t_ray_info *info, int is_horizontal);

// calculations_directions_bonus
int				is_looking_right(float angle);
int				is_looking_down(float angle);
int				is_looking_left(float angle);
int				is_looking_up(float angle);

// calculations_directions2_bonus
int				is_looking_north(float angle);
int				is_looking_east(float angle);
int				is_looking_south(float angle);
int				is_looking_west(float angle);

// calculations_utils_bonus
int				is_position_in_map(t_game *game, int pos_y, int pos_x);
int				is_wall(t_game *game, float xv, float yv);
int				get_h_drctn(float current_angle, float *y, float *len_y);
int				get_v_drctn(float current_angle, float *x, float *len_x);
float			calculate_len(t_game *game, float x, float y);

// calculations_utils2_bonus
float			angle_check(float angle);
float			get_min(float a, float b);
int				is_blocked(t_game *game, int x, int y);

// render_bonus
void			draw_ceiling(t_game *game, int index_of_ray, int top);
void			draw_floor(t_game *game, int index_of_ray, int bottom);
void			rendering_wall(t_game *game, t_ray ray);

// render_utils_bonus
float			fish_eye_crct(t_game *game, float ray_len, float current_angle);
void			calc_wallslice_height(float *top, float *bottom);
void			drawpixel(mlx_image_t *image, float x, float y, uint32_t color);
int				ft_surface(t_game *game);
int				get_rgba_colors_hex(int red, int green, int blue, int alpha);

// render_wall_bonus
int				get_draw_start(int top);
float			calculate_wall_x(t_ray ray);
int				calculate_tex_x(float wall_x, mlx_texture_t *tex, t_ray ray);
void			wallpxls(t_wall_data *d);
void			draw_wall(t_game *g, t_ray ray, int top, int bottom);

// render_wall_bonus2
char			get_shade(t_ray ray);
int				get_dr_end(float bottom);
uint32_t		apply_shading(uint32_t color, char shade);
int				is_door_open(t_game *game, int x, int y);
int				check_open_door(t_game *g, t_ray ray);

// render_wall_utils_bonus
mlx_texture_t	*get_texture(t_game *game, t_ray ray);
double			get_step_size(t_game *game, mlx_texture_t *texture, int height);
int				get_xpos(t_game *game, t_ray ray, mlx_texture_t *texture);
int				get_pxl_clr(mlx_texture_t *texture, int x, int y);

// load_textures_mini_bonus
void			ft_set_color_minimap_char(mlx_image_t *image, uint32_t color);
int				ft_load_textures_minimap(t_game *game);

// ft_exit
void			call_exit_map_textrs(t_game *game);
void			call_exit_map_textrs_addon(t_game *game);
void			free_doors(t_map *map);
void			call_exit_map(t_game *game);
void			call_exit(t_game *game);

// ft_init
void			ft_initialize_player(t_game *game);
mlx_t			*ft_init_window(t_game *game);
void			ft_initialize_game(t_game *game);
void			ft_initialize(t_game *game, int argc, char **argv);

// doors_actions_bonus

int				is_ray_out_of_bounds(t_game *game, t_dctx *ray);
void			cast_dctx(t_game *game, t_dctx *ray, t_door_finder *df);
float			find_nearest_door(t_game *game, float *door_x, float *door_y);
void			update_door_on_map(t_game *game, t_door *door, int map_x,
					int map_y);
void			toggle_door(t_game *game, int map_x, int map_y);

// doors_actions_bonus2
void			init_ray(t_game *game, t_dctx *ray);
void			update_ray_position(t_dctx *ray);

// loop_bonus
void			key_listener(t_game *game, mlx_key_data_t kd, float distance);
void			key_hook(mlx_key_data_t kd, void *param);
void			update_game_state(void *param);
void			mouse_rotate(void *g);
void			start_game(t_game *game);

// loop_bonus2
void			calc_delta(t_game *game, char operator, int factor);

// move_bonus
void			i_like_to_move_it_move_it(t_game *game, float new_x,
					float new_y);
int				check_move_up(t_game *game);
int				check_move_down(t_game *game);
int				check_move_left(t_game *game);
int				check_move_right(t_game *game);

// utils_bonus
void			check_collision(t_game *game, float *new_x, float *new_y);
char			get_cellchar(t_game *game, int x, int y);

#endif
