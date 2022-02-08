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
	parsing/pheader.c \
	parsing/body.c \
	parsing/pchars.c \
	parsing/pcolors.c \
	header.c \
	global.c \
	minilibx.c \
	main.c \
}

OUTPUT = ${INPUT:.c=.o}

MINILIBX = ./minilibx/*.a

all: ${NAME}

${MINILIBX}:
	cd minilibx && ./configure

.c.o: ${MINILIBX}
	gcc -Wall -Wextra -Werror -g -c $< -o ${<:.c=.o} -I sources -Lminilibx -lm -lmlx -lXext -lX11

${NAME}: ${OUTPUT}
	gcc -Wall -Wextra -Werror -g ${OUTPUT} -o ${NAME} -I sources -Lminilibx -lm -lmlx -lXext -lX11

clean:
	rm -f ${OUTPUT}

fclean:	clean
	rm -f ${NAME}

re: fclean all

x: fclean all
	rm -f ${OUTPUT}
