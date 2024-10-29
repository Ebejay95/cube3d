/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:14:01 by ajehle            #+#    #+#             */
/*   Updated: 2024/10/29 11:35:33 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./../libft/libft.h"
# include "./../mlx42/include/MLX42/MLX42.h"
# include "defs.h"
# include "structs.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>

// map_content_check_spot
void			check_the_spot_down(t_map *map, int ydex, int xdex, int *err);
void			check_the_spot_up(t_map *map, int ydex, int xdex, int *err);
void			check_the_spot_left(t_map *map, int ydex, int xdex, int *err);
void			check_the_spot_right(t_map *map, int ydex, int xdex, int *err);
void			check_the_spot(t_map *map, int ydex, int xdex, int *err);

// map_content_flood
void			init_flood(t_map *map);
void			flood_one(char *ref, int *check, char *work);
int				check_xy_nexts(t_map *map, int ydex, int xdex);
void			flood(t_map *map);

// map_content_spawn
void			set_spawn_point(t_map *map, int x, int y);
void			handle_multiple_spawns(t_map *map, int y, int x, int *err);
void			check_spawn_cell(t_map *map, int y, int x, int *err);
void			handle_no_spawns(t_map *map, int *err);
void			check_spawn(t_map *map, int *err);

// map_content_validations
void			check_chars(t_map *map, int *err);
int				has_defined_insides(t_map *map);
void			map_validation(t_map *map, int *err);
void			clear_validation(t_map *m);
void			get_map_content(int fd, int *err, t_game *game);

// map_meta_helper
char			*get_textr_path(char *line, size_t size, int *err);
char			*trim_whitespace_and_newline(char *str);
uint32_t		create_color(int r, int g, int b);
int				validate_color_component(char *component);
int				validate_color_split(char **split);

// map_meta_parser
char			**split_and_trim(char *str, char s);
uint32_t		parse_color(char *str, int start, int *err);
void			set_color_meta(int *err, char *line, t_game *g, char kind);
void			set_textr_meta(int *err, char *line, t_game *g, char ornttn);

// map_meta_validations
int				check_all_meta(t_game *game);
int				got_meta_line(t_game *game, char *s1, char *s2, size_t n);
void			retreive_meta(char *line, int *err, t_game *game);
void			get_map_meta(int fd, int *err, t_game *game);

// map_parser_helper
size_t			count_lines(char *str);
int				alloc_and_cpy_line(char **result, t_splt_ctx *ctx, size_t len);
char			**split_lines_init(size_t count);
char			**split_lines_process(char **result, t_splt_ctx *ctx);
char			**split_lines(char *str, size_t count);

// map_parser_helper2
void			free_splits(char **splits);
void			update_map_bounds(char c, t_map_bounds *bounds, int j);
void			find_map_width_init(t_map_bounds *bounds);
void			find_map_width_process(char **splits, int i,
					t_map_bounds *bounds);
void			find_map_width(char **splits, t_map_bounds *bounds);

// map_parser_helper3
char			*create_new_line(char *old_line, t_map_bounds *bounds);

// map_parser_rect
char			**allocate_result(size_t count);
char			**allocate_rect_array(int num_rows);
char			**map_split(char *str);

// map_parser_trimmer
int				is_map_line(char *line);
void			find_map_bounds(char **splits, int *start, int *end);

// map_parser
void			trim_map_content(char **splits, t_map_bounds *bounds);
int				allocate_map_content(t_map *map);
int				copy_map_content_process(t_map *map, char **splits, int start,
					int i);
int				copy_map_content(t_map *map, char **splits, int start);
void			parse_map_array(t_map *map, char **splits);

// map_printers
void			ft_printmetas(t_map *map);
void			print_map(t_map *map);
void			print_map_error(t_map *map, int ey, int ex);

// map_validation
int				validate_map(t_game *game, char *filename);
int				validate_input(int argc, char **argv);
void			setup_game_stuff(t_game *game);
void			get_map(t_game *game, int argc, char **argv);

// calculations_directions
int				is_looking_right(float angle);
int				is_looking_down(float angle);
int				is_looking_left(float angle);
int				is_looking_up(float angle);

// calculations_directions2
int				is_looking_north(float angle);
int				is_looking_east(float angle);
int				is_looking_south(float angle);
int				is_looking_west(float angle);

// calculations_utils
int				is_position_in_map(t_game *game, int pos_y, int pos_x);
int				is_wall(t_game *game, float xv, float yv);
int				get_h_drctn(float current_angle, float *y, float *len_y);
int				get_v_drctn(float current_angle, float *x, float *len_x);
float			calculate_len(t_game *game, float x, float y);

// calculations_utils2
float			angle_check(float angle);
float			get_min(float a, float b);
int				is_blocked(t_game *game, int x, int y);

// calculations
float			get_len_to_horizontal_wall(t_game *game, t_ray *ray);
float			get_len_to_vertical_wall(t_game *game, t_ray *ray);
int				ray_calculation(t_game *game);

// render_utils
float			fish_eye_crct(t_game *game, float ray_len, float current_angle);
void			calc_wallslice_height(float *top, float *bottom);
void			drawpixel(mlx_image_t *image, float x, float y, uint32_t color);
int				ft_surface(t_game *game);
int				get_rgba_colors_hex(int red, int green, int blue, int alpha);

// render_wall_utils
mlx_texture_t	*get_texture(t_game *game, t_ray ray);
double			get_step_size(t_game *game, mlx_texture_t *texture, int height);
int				get_xpos(t_game *game, t_ray ray, mlx_texture_t *texture);
int				get_pxl_clr(mlx_texture_t *texture, int x, int y);

// render_wall
char			get_shade(t_ray ray);
int				get_dr_end(float bottom);
uint32_t		apply_shading(uint32_t color, char shade);
void			draw_wall(t_game *g, t_ray ray, int top, int bottom);

// render
void			draw_ceiling(t_game *game, int index_of_ray, int top);
void			draw_floor(t_game *game, int index_of_ray, int bottom);
void			rendering_wall(t_game *game, t_ray ray);

// load_textures_mini
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

// loop
void			calc_delta(t_game *game, char operator);
void			key_hook(mlx_key_data_t kd, void *param);
void			update_game_state(void *param);
void			start_game(t_game *game);

// move
void			i_like_to_move_it_move_it(t_game *game, float new_x,
					float new_y);
int				check_move_up(t_game *game);
int				check_move_down(t_game *game);
int				check_move_left(t_game *game);
int				check_move_right(t_game *game);

// utils
void			check_collision(t_game *game, float *new_x, float *new_y);
char			get_cellchar(t_game *game, int x, int y);

#endif
