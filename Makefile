# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/22 12:10:30 by egeraldo          #+#    #+#              #
#    Updated: 2024/05/22 14:42:55 by egeraldo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = cub3D
CFLAGS =  -g3 -Wunreachable-code #-Ofast -Wextra -Wall -Werror

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
LIBS_PATH = ./libs/
INCLUDES_PATH = -I ./include -I $(LIBMLX)/include
MLX_PATH = $(LIBS_PATH)MLX42/build/libmlx42.a -ldl -lglfw -lm

MANDATORY_SOURCES = \
	test.c

OBJECTS = $(addprefix $(BIN_PATH), $(MANDATORY_SOURCES:%.c=%.o))

all: $(BIN_PATH) $(NAME) $(MLX_PATH)

$(BIN_PATH)%.o: $(MANDATORY_SOURCES_PATH)%.c
	@echo $(BLUE)[Compiling philosophers]$(COLOR_LIMITER) $(WHITE)$(notdir $(<))$(COLOR_LIMITER)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES_PATH)
	@echo " "

$(NAME): $(OBJECTS)
	@echo $(CYAN)" --------------------------------------------------"$(COLOR_LIMITER)
	@echo $(CYAN)"| cub3D executable was created successfully!! |"$(COLOR_LIMITER)
	@echo $(CYAN)"--------------------------------------------------"$(COLOR_LIMITER)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(MLX_PATH) $(INCLUDES_PATH)
	@echo " "

$(BIN_PATH):
	@mkdir -p $(BIN_PATH)

clean:
	@echo $(RED)[Removing Objects]$(COLOR_LIMITER)
	@rm -rf $(BIN_PATH)

fclean: clean
	@echo $(RED)[Removing $(NAME) executable]$(COLOR_LIMITER)
	@rm -rf $(NAME)

re: fclean
	@make --no-print-directory

.PHONY: all clean fclean re bonus