MAKEFLAGS += --silent

SRC = ./src/

FILES_C =	$(SRC)main.c \
			$(SRC)ft_verif_file.c \
			$(SRC)ft_parsing_file.c \
			$(SRC)ft_parsing_file_rgb.c \
			$(SRC)ft_parsing_file_texture.c \
			$(SRC)ft_parsing_map.c \
			$(SRC)ft_parsing_map_spaces.c \
			$(SRC)ft_key_hook.c \
			$(SRC)ft_image.c \
			$(SRC)ft_free.c 

LIBFT_PATH = ${SRC}ft_printf/

MLX_PATH = ./minilibx-linux/

LIBFT = -L ${LIBFT_PATH} -lftprintf

MLX = -L ${MLX_PATH} -lmlx -lXext -lX11

FILES_O = ${FILES_C:.c=.o}

FILES_H = ./cub3d.h

CFLAGS = -Wall -Wextra -Werror -g

CC = gcc

NAME = cub3D

all: ${NAME}

${LIBFT}:
	@make -C ${LIBFT_PATH} all bonus
	@make -C ${MLX_PATH}

${NAME}: ${LIBFT} ${FILES_O}
	${CC} ${FLAGS} ${FILES_O} ${MLX} ${LIBFT} -I ${FILES_H} -o ${NAME} -lm \
		&& echo "Make done successfully." \ || echo "Doesn't work, sadge. :c"

clean:
	rm -f ${FILES_O}
	make -C ${LIBFT_PATH} clean
	make -C ${MLX_PATH} clean

fclean: clean
	rm -f ${NAME}
	rm -rf ./execute
	make -C ${LIBFT_PATH} fclean \
	&& echo "Fclean done successfully." \ || echo "Haha your fclean suck."

re: fclean all
