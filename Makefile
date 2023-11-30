MAKEFLAGS += --silent

SRC_DIR := ./src

SRC_FILES := main.c \
			ft_verif_file.c 

OBJ_DIR := ./obj

EXEC := cub3D

OBJ_FILES := $(addprefix $(OBJ_DIR)/,$(SRC_FILES:.c=.o))

CC := gcc

CFLAGS := -Wall -Wextra -Werror -lm -g

LFT := ./ft_printf/libftprintf.a
LIB := $(SRC_DIR)/ft_printf -lftprintf

MLX_PATH := ./minilibx-linux
MLX := -L $(MLX_PATH) -lmlx -lXext -lX11

all: $(OBJ_DIR) $(LFT) $(EXEC)

RM := rm -f

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LFT):
	@make -s -C $(SRC_DIR)/ft_printf/ all

$(EXEC): $(OBJ_FILES)
	@$(CC) $(CFLAGS) $^ $(LIB) $(MLX) -o $@
	@echo "\033[32m✅ Done! Executable $(EXECUTABLE) is ready.\033[0m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) -r $(OBJ_DIR)
	@make -s -C $(SRC_DIR)/ft_printf/ clean
	@echo "\033[32m✅ Done! Object files removed.\033[0m"

fclean: clean
	@$(RM) $(EXECUTABLE)
	@make -s -C $(SRC_DIR)/ft_printf/ fclean
	@echo "\033[32m✅ Done! Executable $(EXECUTABLE) removed.\033[0m"

re: fclean all

.PHONY: all clean fclean re
