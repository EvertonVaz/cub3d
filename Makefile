NAME		:= cub3D
CC			:= gcc
CFLAGS		:= -Wextra -Wall -Werror -g3

# Colors Definition
BLUE = "\033[34;1m"
GREEN = "\033[32;1m"
RED = "\033[31;1m"
CYAN = "\033[36;1;3;208m"
WHITE = "\033[37;1;4m"
COLOR_LIMITER = "\033[0m"

# Paths for libraries
LIBMLX_PATH		:= ./libs/MLX42
LIBFT_PATH		:= ./libs/libft/
BIN_PATH		:= ./bin/
LIBFT			:= libft.a

FILES			:= \
	main.c check_args.c utils.c player.c \
	maps/handle_map.c maps/handle_texture.c maps/handle_colors.c maps/check_duplicates.c maps/check_map.c \
	render/map_render.c render/raycasting.c render/raycating_utils.c \
	moves/player_walk.c moves/mouse_move.c


HEADERS			:= -I ./cub3d.h -I $(LIBMLX_PATH)/include -I ./libft
LIBS			:= $(LIBMLX_PATH)/build/libmlx42.a -ldl -lglfw -pthread -lm $(LIBFT_PATH)$(LIBFT)
SRCS			:= $(addprefix ./src/, $(FILES))
OBJS			:= $(patsubst ./src/%.c,$(BIN_PATH)%.o,$(SRCS))


all: libft $(LIBMLX_PATH)/build/libmlx42.a $(BIN_PATH) $(NAME)

libft:
ifeq ($(wildcard $(LIBFT)),)
	@make -C $(LIBFT_PATH) --no-print-directory
endif

$(LIBMLX_PATH)/build/libmlx42.a:
	@cmake $(LIBMLX_PATH) -B $(LIBMLX_PATH)/build && make -C $(LIBMLX_PATH)/build -j4 && printf "\n"
	@echo $(CYAN)" --------------------------------------------------"$(COLOR_LIMITER)
	@echo $(CYAN)"|   MLX42 executable was created successfully!!   |"$(COLOR_LIMITER)
	@echo $(CYAN)"--------------------------------------------------"$(COLOR_LIMITER)

$(BIN_PATH)%.o: ./src/%.c
	@echo $(BLUE)[Compiling cub3D]$(COLOR_LIMITER) $(WHITE)$(notdir $(<))$(COLOR_LIMITER)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "\n"

$(NAME): $(OBJS)
	@echo $(CYAN)" --------------------------------------------------"$(COLOR_LIMITER)
	@echo $(CYAN)"|   cub3D executable was created successfully!!   |"$(COLOR_LIMITER)
	@echo $(CYAN)"--------------------------------------------------"$(COLOR_LIMITER)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)
	@echo " "

$(BIN_PATH):
	@mkdir -p $(BIN_PATH)
	@mkdir -p $(BIN_PATH)maps
	@mkdir -p $(BIN_PATH)render
	@mkdir -p $(BIN_PATH)moves

clean:
	@echo $(RED)[Removing Objects]$(COLOR_LIMITER)
	@rm -rf $(BIN_PATH)
	@make clean -sC ./libs/libft --no-print-directory

fclean: clean
	@echo $(RED)[Removing $(NAME) executable]$(COLOR_LIMITER)
	@rm -rf ./libs/libft/libft.a
	@rm -rf $(NAME)


re: fclean all

.PHONY: all clean fclean re