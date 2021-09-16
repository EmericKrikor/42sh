##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile
##

NAME	= mysh

CC	= gcc

RM	= rm -f

SRCS	= ./src/mainc.c \
		  ./shellfunction/init_shell.c \
		  ./shellfunction/strtwa.c \
		  ./shellfunction/my_setenv.c \
		  ./shellfunction/my_cd.c \
		  ./shellfunction/refreshenv.c \
		  ./shellfunction/str_to_word_array.c \
		  ./shellfunction/affichage.c \
		  ./shellfunction/parth_path.c \
		  ./shellfunction/search.c \
		  ./shellfunction/write_error.c

OBJS	= $(SRCS:.c=.o)

CPPFLAGS = -I ./include/
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)
	 $(RM) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
