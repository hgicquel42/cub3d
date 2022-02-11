NAME = cub3d

INPUT = ${addprefix \
	sources/, \
	utils/chars.c \
	utils/numbers.c \
	utils/strings.c \
	utils/strings2.c \
	utils/files.c \
	utils/print.c \
	utils/split.c \
	utils/colors.c \
	utils/pointers.c \
	utils/vector.c \
	utils/vector2.c \
	utils/vector3.c \
	parsing/pheader.c \
	parsing/pbody.c \
	parsing/pchars.c \
	parsing/pcolors.c \
	header.c \
	global.c \
	minilibx.c \
	hooks.c \
	textures.c \
	image.c \
	move.c \
	player.c \
	keyboard.c \
	raycast.c \
	raycast2.c \
	path.c \
	loop.c \
	draw.c \
	minimap.c \
	main.c \
}

OUTPUT = ${INPUT:.c=.o}

MINILIBX = ./minilibx/*.a

all: ${NAME}

${MINILIBX}:
	cd minilibx && ./configure

.c.o: ${MINILIBX}
	gcc -Wall -Wextra -Werror -g -c $< -o ${<:.c=.o} -I sources -I minilibx -Lminilibx -lm -lmlx -lXext -lX11

${NAME}: ${OUTPUT}
	gcc -Wall -Wextra -Werror -g ${OUTPUT} -o ${NAME} -I sources -I minilibx -Lminilibx -lm -lmlx -lXext -lX11

clean:
	rm -f ${OUTPUT}

fclean:	clean
	rm -f ${NAME}

re: fclean all

x: fclean all
	rm -f ${OUTPUT}
