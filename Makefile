# Compiler and flags:
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS  = -lmlx -framework OpenGL -framework AppKit


# Project:
NAME = fractol

# Source files:
SRCS = main.c src/colors.c src/events.c src/fractals.c src/utils.c

# Object files:
OBJS = $(SRCS:.c=.o)

# Rules:
all: $(NAME)

$(NAME): $(OBJS) fractol.h
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
