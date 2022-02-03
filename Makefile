NAME = cub3d

INPUT = \
	main.c \
	check.c \
	libft.c \
	map.c \
	chars.c \
	strings.c \
	numbers.c \
	files.c \
	print.c \
	split.c \

OUTPUT = ${INPUT:.c=.o}

all: ${NAME}

.c.o:	
	gcc -Wall -Wextra -Werror -g -c $< -o ${<:.c=.o}

${NAME}: ${OUTPUT}
	gcc -Wall -Wextra -Werror -g ${OUTPUT} -o ${NAME}

clean:
	rm -f ${OUTPUT}

fclean:	clean
	rm -f ${NAME}

re: fclean all

x: fclean all
	rm -f ${OUTPUT}
