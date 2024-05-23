# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/22 12:10:30 by egeraldo          #+#    #+#              #
#    Updated: 2024/05/23 14:38:05 by egeraldo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = cub3D
CFLAGS = -Wall -Wextra -Werror -g3
RFLAGS = -O3 -ffast-math -fno-stack-protector
MFLAGS = -Iinclude -ldl -lglfw -pthread -lm

# Colors Definition
BLUE = "\033[34;1m"
GREEN = "\033[32;1m"
RED = "\033[31;1m"
CYAN = "\033[36;1;3;208m"
WHITE = "\033[37;1;4m"
COLOR_LIMITER = "\033[0m"

# Paths for libraries
BIN_PATH = ./bin/
MANDATORY_SOURCES_PATH = ./src/
LIBS_PATH = ./libs

MLX_PATH = $(LIBS_PATH)/MLX42
MLX = $(MLX_PATH)/build/libmlx42.a

LIBFT_PATH = $(LIBS_PATH)/libft
LIBFT = $(LIBFT_PATH)/libft.a

INCLUDES_PATH = -I ./include -I $(MLX_PATH)/include/MLX42 -I $(LIBFT_PATH)

MANDATORY_SOURCES = \
	test.c

OBJECTS = $(addprefix $(BIN_PATH), $(MANDATORY_SOURCES:%.c=%.o))

all: libft $(BIN_PATH) $(NAME)

libft:
ifeq ($(wildcard $(LIBFT)),)
	@make -C $(LIBFT_PATH) --no-print-directory
	@echo $(CYAN)" --------------------------------------"$(COLOR_LIMITER)
	@echo $(CYAN)"|  LIBFT  Was Compiled Successfully!! |"$(COLOR_LIMITER)
	@echo $(CYAN)"--------------------------------------"$(COLOR_LIMITER)
	@echo " "
endif

$(BIN_PATH)%.o: $(MANDATORY_SOURCES_PATH)%.c
	@echo $(BLUE)[Compiling cub3D]$(COLOR_LIMITER) $(WHITE)$(notdir $(<))$(COLOR_LIMITER)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES_PATH)
	@echo " "

$(NAME): $(OBJECTS)
	@echo $(CYAN)" --------------------------------------------------"$(COLOR_LIMITER)
	@echo $(CYAN)"| cub3D executable was created successfully!! |"$(COLOR_LIMITER)
	@echo $(CYAN)"--------------------------------------------------"$(COLOR_LIMITER)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(INCLUDES_PATH) $(MLX) -L $(LIBFT) -lft
	@echo " "

$(BIN_PATH):
	@mkdir -p $(BIN_PATH)

clean:
	@echo $(RED)[Removing Objects]$(COLOR_LIMITER)
	@make fclean -C $(LIBFT_PATH) --no-print-directory
	@rm -rf $(BIN_PATH)

fclean: clean
	@echo $(RED)[Removing $(NAME) executable]$(COLOR_LIMITER)
	@rm -rf $(NAME)

re: fclean
	@make --no-print-directory

.PHONY: all clean fclean re bonus