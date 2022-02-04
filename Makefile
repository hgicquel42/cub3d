NAME = cub3d

CFLAGS = -Wall -Wextra -Werror

CC = gcc

MINILIBX = ./minilibx-linux/*.a

INPUT = \
	main.c \
	chars.c \
	numbers.c \
	strings.c \
	strings2.c \
	files.c \
	print.c \
	split.c \
	header.c \
	pointer.c \
	global.c \

OBJ = ${INPUT:.c=.o}

.c.o: $(MINILIBX)
			gcc $(CFLAGS) -c $< -o ${<:.c=.o}

all: $(NAME)

$(MINILIBX):
	cd ./minilibx-linux && ./configure

$(NAME): $(MINILIBX) $(OBJ)
			$(CC) $(OBJ) $(CFLAGS) -I -g3 -Lmlx_Linux -lmlx_Linux -L ./minilibx-linux -Imlx_Linux -L ./libft -lXext -lX11 -lm -lz -o $(NAME)

clean:
	rm -f ${OBJ}

fclean:	clean
	rm -f ${NAME}

re: fclean all

x: fclean all
	rm -f ${OBJ}
