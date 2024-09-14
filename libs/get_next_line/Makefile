NAME = libget_next_line.a
CFLAGS = -Wall -Werror -Wextra
CC = cc
REMOVE = rm -f

FUNC =	get_next_line.c \
		get_next_line_utils.c

OBJ = ${FUNC:.c=.o}

BFUNCTIONS =	get_next_line_utils_bonus.c \
				get_next_line_bonus.c\

BOBJ = ${BFUNCTIONS:.c=.o}

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ) : $(FUNC)
	$(CC) $(CFLAGS) -c $(FUNC)

bonus : $(OBJECTS) $(BOBJ)
	ar rcs $(NAME) $(OBJECTS) $(BOBJ)

$(BOBJ): $(BFUNCTIONS)
	$(CC) $(FLAGS) -c $(BFUNCTIONS)

clean :
	$(REMOVE) $(OBJ) $(BOBJ)

fclean : clean
	$(REMOVE) $(NAME)

re : fclean all

.PHONY : all, bonus, clean, fclean, re
