# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/08 15:31:09 by ajehle            #+#    #+#              #
#    Updated: 2024/02/15 13:48:21 by ajehle           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
CFLAGS		= -Wall -Werror -Wextra
CC			= cc
REMOVE		= rm -rf
OBJ_DIR		= ./obj
SRC_DIR		= src

# INTERNAL FUNCTIONS
FUNCTIONS	=	$(SRC_DIR)/ft_printf.c \
				$(SRC_DIR)/ft_printf_helper.c

# INTERNAL OBJECT
OBJECTS		= $(addprefix $(OBJ_DIR)/, $(notdir $(FUNCTIONS:.c=.o)))

all : $(NAME)

# INTERNAL RULE
$(NAME) : $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

# DIRECTORY
$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(REMOVE) $(OBJECTS)
	$(REMOVE) $(OBJ_DIR)

fclean : clean
	$(REMOVE) $(NAME)
	$(REMOVE) $(OBJ_DIR)

re : fclean all

.PHONY : all, clean, fclean, re