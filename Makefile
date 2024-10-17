# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/08 15:31:09 by ajehle            #+#    #+#              #
#    Updated: 2024/10/17 12:06:04 by ajehle           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------------------------------------#
#--------------                       PRINT                       -------------#
#------------------------------------------------------------------------------#

BLACK := \033[90m
RED := \033[31m
GREEN := \033[32m
YELLOW := \033[33m
BLUE := \033[34m
MAGENTA := \033[35m
CYAN := \033[36m
X := \033[0m

SUCCESS := \n$(BLACK)\
███████████████████████████████████████████$(X)\n\
$(X)\n\
███████  █     █  ███████  ███████  ██████  $(X)\n\
█        █     █  █     █        █  █     █ $(X)\n\
█        █     █  ██████   ██████   █     █ $(X)\n\
█        █     █  █     █        █  █     █ $(X)\n\
███████  ███████  ███████  ███████  ██████  $(X)\n\
$(X)\n\
$(BLACK)███████████████████████████████████████████$(X)\n\

#------------------------------------------------------------------------------#
#--------------                      GENERAL                      -------------#
#------------------------------------------------------------------------------#

NAME=cub3d
NAME_BONUS=cub3d_bonus

#------------------------------------------------------------------------------#
#--------------                       FLAGS                       -------------#
#------------------------------------------------------------------------------#

CC=cc
CFLAGS=-Wall -Wextra -Werror
LDFLAGS=

ifeq ($(DEBUG), 1)
	CFLAGS += -fsanitize=address -g
endif

DEPFLAGS=-MMD -MP

#------------------------------------------------------------------------------#
#--------------                        DIR                        -------------#
#------------------------------------------------------------------------------#

OBJ_DIR := ./obj
DEP_DIR := $(OBJ_DIR)/.deps
INC_DIRS := .
SRC_DIRS := .

vpath %.c $(SRC_DIRS)
vpath %.h $(INC_DIRS)
vpath %.d $(DEP_DIR)

#------------------------------------------------------------------------------#
#--------------                        LIBS                       -------------#
#------------------------------------------------------------------------------#

LIBFT_DIR = libft
LIBFT = libft.a
LIBFT_LIB = $(LIBFT_DIR)/$(LIBFT)
LIBFTFLAGS = -L$(LIBFT_DIR) -lft
LIBFT_REPO = https://github.com/Ebejay95/libft.git

MLXFT_DIR = ./mlx42
MLXFT = libmlx42.a
MLXFT_BUILD_DIR = ./mlx_build
MLXFT_LIB = $(MLXFT_BUILD_DIR)/$(MLXFT)
MLXFTFLAGS = -L$(MLXFT_BUILD_DIR) -lmlx42 -Iinclude -lglfw -framework Cocoa -framework OpenGL -framework IOKit
MLXFT_REPO = https://github.com/codam-coding-college/MLX42.git


SYSLIBFLAGS =

#------------------------------------------------------------------------------#
#--------------                        SRC                        -------------#
#------------------------------------------------------------------------------#

SRCS=	src/utils/ft_exit.c \
		src/utils/ft_init.c \
		src/textures/load_textures_mini.c \
		src/textures/textures_wall.c \
		src/loop.c \
		src/main.c \
		src/move.c \
		src/utils.c \
		src/rendering/render.c \
		src/rendering/render_wall.c \
		src/rendering/render_wall_utils.c \
		src/rendering/render_utils.c \
		src/raycasting/calculations.c \
		src/raycasting/calculations_directions.c \
		src/raycasting/calculations_directions2.c \
		src/raycasting/calculations_utils.c \
		src/raycasting/calculations_utils2.c \
		src/parser/map_content_check_spot.c \
		src/parser/map_content_flood.c \
		src/parser/map_content_spawn.c \
		src/parser/map_content_validations.c \
		src/parser/map_meta_helper.c \
		src/parser/map_meta_parser.c \
		src/parser/map_meta_validations.c \
		src/parser/map_validation.c \
		src/parser/map_parser_helper.c \
		src/parser/map_parser_helper2.c \
		src/parser/map_parser_helper3.c \
		src/parser/map_parser_rect.c \
		src/parser/map_parser_trimmer.c \
		src/parser/map_parser.c \
		src/parser/map_printers.c \


BONUS_SRCS= src_bonus/utils/ft_exit_bonus.c \
		src_bonus/audio/audio_bonus.c \
		src_bonus/audio/audio_bonus2.c \
		src_bonus/utils/ft_init_bonus.c \
		src_bonus/textures/load_textures_mini_bonus.c \
		src_bonus/textures/textures_wall_bonus.c \
		src_bonus/doors_actions_bonus.c \
		src_bonus/doors_actions_bonus2.c \
		src_bonus/loop_bonus.c \
		src_bonus/loop_bonus2.c \
		src_bonus/main_bonus.c \
		src_bonus/move_bonus.c \
		src_bonus/utils_bonus.c \
		src_bonus/rendering/render_bonus.c \
		src_bonus/rendering/render_wall_bonus.c \
		src_bonus/rendering/render_wall_utils_bonus.c \
		src_bonus/rendering/render_utils_bonus.c \
		src_bonus/raycasting/calculations_bonus.c \
		src_bonus/raycasting/calculations_directions_bonus.c \
		src_bonus/raycasting/calculations_directions2_bonus.c \
		src_bonus/raycasting/calculations_utils_bonus.c \
		src_bonus/raycasting/calculations_utils2_bonus.c \
		src_bonus/parser/map_content_check_spot_bonus.c \
		src_bonus/parser/map_content_flood_bonus.c \
		src_bonus/parser/map_content_doors_bonus.c \
		src_bonus/parser/map_content_spawn_bonus.c \
		src_bonus/parser/map_content_validations_bonus.c \
		src_bonus/parser/map_content_validation_bonus2.c \
		src_bonus/parser/map_content_validation_bonus3.c \
		src_bonus/parser/map_meta_helper_bonus.c \
		src_bonus/parser/map_meta_parser_bonus.c \
		src_bonus/parser/map_meta_validations_bonus.c \
		src_bonus/parser/map_validation_bonus.c \
		src_bonus/parser/map_parser_helper_bonus.c \
		src_bonus/parser/map_parser_helper2_bonus.c \
		src_bonus/parser/map_parser_helper3_bonus.c \
		src_bonus/parser/map_parser_rect_bonus.c \
		src_bonus/parser/map_parser_trimmer_bonus.c \
		src_bonus/parser/map_parser_bonus.c \
		src_bonus/parser/map_printers_bonus.c \
		src_bonus/minimap/minimap_bonus.c \
		src_bonus/minimap/minimap_bonus2.c \
		src_bonus/minimap/minimap_bonus3.c \

#------------------------------------------------------------------------------#
#--------------                      OBJECTS                      -------------#
#------------------------------------------------------------------------------#

OBJECTS := $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))
BONUS_OBJECTS := $(addprefix $(OBJ_DIR)/, $(BONUS_SRCS:%.c=%.o))

#------------------------------------------------------------------------------#
#--------------                      COMPILE                      -------------#
#------------------------------------------------------------------------------#

.PHONY: all clean fclean re libft mlx init-submodules remove-submodules

all: init-submodules $(NAME)

bonus: init-submodules $(NAME_BONUS)

-include $(OBJECTS:.o=.d)
-include $(BONUS_OBJECTS:.o=.d)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

init-submodules: init-libft init-mlx

init-libft:
	@if [ ! -d "$(LIBFT_DIR)" ]; then \
		git submodule add $(LIBFT_REPO) $(LIBFT_DIR) || (echo "$(RED)Failed to add libft submodule$(X)" && exit 1); \
	elif [ -z "$$(ls -A $(LIBFT_DIR) 2>/dev/null)" ]; then \
		git submodule update --init --recursive $(LIBFT_DIR) || (echo "$(RED)Failed to update libft submodule$(X)" && exit 1); \
	fi

remove-submodules: remove-libft #remove-mlx

remove-libft:
	@if [ -d "$(LIBFT_DIR)" ]; then \
		git submodule deinit -q -f $(LIBFT_DIR) > /dev/null 2>&1; \
		git rm -q -f $(LIBFT_DIR) > /dev/null 2>&1; \
		rm -rf .git/modules/$(LIBFT_DIR) > /dev/null 2>&1; \
	fi

remove-mlx:
	@if [ -d "$(MLXFT_DIR)" ]; then \
		git submodule deinit -q -f $(MLXFT_DIR) > /dev/null 2>&1; \
		git rm -q -f $(MLXFT_DIR) > /dev/null 2>&1; \
		rm -rf .git/modules/$(MLXFT_DIR) > /dev/null 2>&1; \
		rm -rf ./mlx42 > /dev/null 2>&1; \
	fi

$(LIBFT_LIB): init-libft
	@if [ -d "$(LIBFT_DIR)" ] && [ -f "$(LIBFT_DIR)/Makefile" ]; then \
		$(MAKE) -C $(LIBFT_DIR); \
	else \
		exit 1; \
	fi

init-mlx:
	@if [ ! -d "$(MLXFT_DIR)" ]; then \
		git submodule add -q $(MLXFT_REPO) $(MLXFT_DIR) > /dev/null 2>&1 || (echo "$(RED)Failed to add MLX42 submodule$(X)" && exit 1); \
	elif [ -z "$$(ls -A $(MLXFT_DIR) 2>/dev/null)" ]; then \
		git submodule update --init --recursive -q $(MLXFT_DIR) > /dev/null 2>&1 || (echo "$(RED)Failed to update MLX42 submodule$(X)" && exit 1); \
	fi

$(MLXFT_LIB): init-mlx
	@if [ ! -f "$(MLXFT_LIB)" ]; then \
		echo "$(YELLOW)Building MLX42...$(X)"; \
		mkdir -p $(MLXFT_BUILD_DIR); \
		cmake -S $(MLXFT_DIR) -B $(MLXFT_BUILD_DIR) && \
		cmake --build $(MLXFT_BUILD_DIR) --parallel || \
		(echo "$(RED)Failed to build MLX42$(X)" && exit 1); \
	fi

$(NAME): $(LIBFT_LIB) $(MLXFT_LIB) $(OBJECTS)
	@$(CC) -o $@ $(OBJECTS) $(LIBFTFLAGS) -L$(MLXFT_BUILD_DIR) -lmlx42 $(MLXFTFLAGS) $(SYSLIBFLAGS) $(LDFLAGS)
	@echo "$(SUCCESS)"

$(NAME_BONUS): $(LIBFT_LIB) $(MLXFT_LIB) $(BONUS_OBJECTS)
	@$(CC) -o $@ $(BONUS_OBJECTS) $(LIBFTFLAGS) $(MLXFTFLAGS) $(SYSLIBFLAGS) $(LDFLAGS)
	@echo "$(SUCCESS)"

clean: remove-submodules
	@rm -rf $(OBJ_DIR)
	@rm -rf $(MLXFT_BUILD_DIR)
	@rm -rf $(LIBFT_DIR)
	@echo "$(RED)Objects deleted$(X)"

fclean: clean
	@rm -rf $(NAME_BONUS)
	@rm -rf $(NAME)
	@echo "$(RED)cube3d deleted$(X)"

re: fclean all
