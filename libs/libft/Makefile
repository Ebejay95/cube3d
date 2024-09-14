NAME		= libft.a
CFLAGS		= -Wall -Werror -Wextra
CC			= cc
REMOVE		= rm -rf
OBJ_DIR		= ./obj
SRC_DIR		= src
INC_DIR		=

# looking for files in subdirectories
vpath %.c $(SRC_DIR)
vpath %.h $(INC_DIR)

# INTERNAL FUNCTIONS
FUNCTIONS = ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isprint.c \
			ft_isascii.c \
			ft_strlen.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_bzero.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_strmapi.c \
			ft_striteri.c

# INTERNAL OBJECT
OBJECTS		= $(addprefix $(OBJ_DIR)/, $(notdir $(FUNCTIONS:.c=.o)))

# # INTERNAL BONUS FUNCTIONS
BFUNCTIONS =	ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c\
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c

# INTERNAL BONUS OBJECT
BOBJECTS		= $(addprefix $(OBJ_DIR)/, $(notdir $(BFUNCTIONS:.c=.o)))

all : $(NAME)

# INTERNAL RULE
$(NAME) : $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

# INTERNAL BONUS RULE
bonus : $(OBJECTS) $(BOBJECTS)
	ar rcs $(NAME) $(OBJECTS) $(BOBJECTS)

# DIRECTORY
$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
		$(REMOVE) $(OBJECTS) $(BOBJECTS)
		$(REMOVE) $(OBJ_DIR)

fclean : clean
		$(REMOVE) $(NAME)
		$(REMOVE) $(OBJ_DIR)

re : fclean

.PHONY : all, bonus, clean, fclean, re