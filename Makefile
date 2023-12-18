NAME = Cub3D
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

LIBFT = ft_printf/libftprintf.a
LIBFT_DIR = ft_printf/
LIBFT_INC = -I $(LIBFT_DIR)/ -lftprintf

MINILIBX = $(MINILIBX_DIR)/libmlx.a
MINILIBX_DIR = minilibx-linux/
MINILIBX_INC = -I $(MINILIBX_DIR)/
MINILIBX_LINK = -L$(MINILIBX_DIR) -lmlx -lXext -lX11 -lm

INC_DIR = includes
SRC_DIR = srcs
OBJ_DIR = obj

INCLUDES = -I$(INC_DIR) $(LIBFT_INC) $(MINILIBX_INC)

SRC_FILES = main.c \
			ft_verif_file.c \
			ft_parsing_file.c \
			ft_parsing_file_rgb.c \
			ft_parsing_file_texture.c \
			ft_parsing_map.c \
			ft_parsing_map_spaces.c \
			ft_key_hook.c \
			ft_image.c \
			ft_free.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Colors
RESET = \033[0m
GREEN = \033[32m
ORANGE_Q = \033[38;2;230;126;34m
GREEN_Q = \033[38;2;60;120;60m
BROWN_Q = \033[38;2;139;69;19m
GREEN_M = \033[38;2;170;180;90m
YELLOW = \033[33m
RED = \033[31m
BLUE = \033[34m

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(MINILIBX_DIR)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MINILIBX) $(MINILIBX_LINK) -o $(NAME)
	@echo "$(GREEN)Compilation successful!$(RESET)"
	@sleep 0
	@clear
	@echo "$(GREEN_Q)__| |___________________________________________________________| |__$(RESET)";
	@echo "$(GREEN_Q)__   ___________________________________________________________   __$(RESET)";
	@echo "$(GREEN_Q)  | |                                                           | |  $(RESET)";
	@echo "$(GREEN_Q)  | |                                                           | |  $(RESET)";
	@echo "$(GREEN_Q)  | |        $(GREEN_M)  ██████╗██╗   ██╗██████╗ ██████╗ ██████╗  $(GREEN_Q)        | |  $(RESET)";
	@echo "$(GREEN_Q)  | |        $(GREEN_M) ██╔════╝██║   ██║██╔══██╗╚════██╗██╔══██╗ $(GREEN_Q)        | |  $(RESET)";
	@echo "$(GREEN_Q)  | |        $(GREEN_M) ██║     ██║   ██║██████╔╝ █████╔╝██║  ██║ $(GREEN_Q)        | |  $(RESET)";
	@echo "$(GREEN_Q)  | |        $(GREEN_M) ██║     ██║   ██║██╔══██╗ ╚═══██╗██║  ██║ $(GREEN_Q)        | |  $(RESET)";
	@echo "$(GREEN_Q)  | |        $(GREEN_M) ╚██████╗╚██████╔╝██████╔╝██████╔╝██████╔╝ $(GREEN_Q)        | |  $(RESET)";
	@echo "$(GREEN_Q)  | |        $(GREEN_M)  ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝ ╚═════╝  $(GREEN_Q)        | |  $(RESET)";
	@echo "$(GREEN_Q)  | |                 $(BROWN_Q)by mescobar and qbanet$(GREEN_Q)                    | |  $(RESET)";
	@echo "$(GREEN_Q)__| |___________________________________________________________| |__$(RESET)";
	@echo "$(GREEN_Q)__   ___________________________________________________________   __$(RESET)";
	@echo "$(GREEN_Q)  | |                                                           | |  $(RESET)";
	@echo ""

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(BLUE)Compiling: $<$(RESET)"

clean:
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MINILIBX_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "$(YELLOW)Cleaning object files...$(RESET)"

fclean:
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(MINILIBX_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "$(YELLOW)Cleaning object files...$(RESET)"
	@rm -f $(NAME)
	@echo "$(RED)Full clean completed!$(RESET)"

re: fclean all

.PHONY: all clean fclean re