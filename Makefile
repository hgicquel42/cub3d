NAME = cub3d

INPUT = ${addprefix \
	sources/, \
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
}

OUTPUT = ${INPUT:.c=.o}

MINILIBX = ./minilibx/*.a

all: ${NAME}

${MINILIBX}:
	cd minilibx && ./configure

.c.o: ${MINILIBX}
	gcc -Wall -Wextra -Werror -g -c $< -o ${<:.c=.o} -Lminilibx -lm -lmlx -lXext -lX11

${NAME}: ${OUTPUT}
	gcc -Wall -Wextra -Werror -g ${OUTPUT} -o ${NAME} -Lminilibx -lm -lmlx -lXext -lX11

clean:
	rm -f ${OUTPUT}

fclean:	clean
	rm -f ${NAME}

re: fclean all

x: fclean all
	rm -f ${OUTPUT}
