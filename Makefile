# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pudry <pudry@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 08:09:16 by pudry             #+#    #+#              #
#    Updated: 2024/09/11 22:04:39 by pudry            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLUE = \\033[1;34m
WHITE = \\033[0;37m
YELLOW = \\033[0;33m
RED = \\033[1;31m
GREEN = \\033[1;32m
BRWN = \\033[0; 33m
GREY = \\033[1;30m

NAME = cub3D
CC = gcc
FLAGS = -Wall -Wextra -Werror #-fsanitize=address
LIBFT = libft/libft.a

MLX = mlx/libmlx.a
INCLUDES = -I/opt/X11/include -Imlx -I libft/includes -I get_next_line/includes -I includes
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

OBJ_DIR = objet/

SRC = $(wildcard src/**/*.c)
SRC += $(wildcard src/*.c)
SRC += $(wildcard utils/*.c)
SRC += $(wildcard get_next_line/src/*.c)

# Création de la liste des fichiers .o correspondants dans le répertoire objet
OBJ = $(patsubst %.c, $(OBJ_DIR)%.o, $(SRC))

all : lib $(NAME)


$(OBJ_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -c -o $@ $< $(INCLUDES)


$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) $(MLX_FLAGS) $(LIBFT) -o $(NAME)

lib :
	@echo $(OBJ)
	@make -C libft/
	@make -C mlx/

clean :
	@rm -f $(OBJ)
	@make clean -C libft/
	@make clean -C mlx/

fclean : clean
	@rm -f $(NAME)
	@make fclean -C libft/

re : fclean all

init :
	git submodule init
	git submodule update


header :
	@echo "${GREEN}"
	@echo "                                                          ████                                                "
	@echo "                                                       ███    ███                                             "
	@echo "                                                    ██▓           ██                                          "
	@echo "                                                ▒██                  ███                                      "
	@echo "                                             ███                        ███                                   "
	@echo "                                          ███                              ███                                "
	@echo "                                        ██                                    ██                              "
	@echo "                                        █ ███                              ███ █                              "
	@echo "                                        █    ███                        ███    █                              "
	@echo "                             ▒█         █       ███                  ███       █         ██                   "
	@echo "                          ███   ███     █           ██            ██           █     ░██   ███                "
	@echo "                       ███         ███  █              ██      ██              █   ██         ███             "
	@echo "                    ███               ███                 ████                 ███                ██          "
	@echo "                 ██                      ███                █               ███                      ██░      "
	@echo "             ░██                            ███             █            ███                            ███   "
	@echo "          ███                                   ██          █         ██                                   ███"
	@echo "          ████                                 ████         █        ████                                 ████"
	@echo "          █   ░██                          ███    █         █        █    ███                          ███   █"
	@echo "          █       ██                    ███       █                  ██      ███                    ██▒      █"
	@echo "          █          ███             ███          █      ██████      ██         ███              ██          █"
	@echo "          █             ███       ███             █   ██        ███  █▒             ██       ███             █"
	@echo "          █                ███ ██░                ███              ███░                ██ ███                █"
	@echo "          █                   █                ███                    ███                █                   █"
	@echo "          █                   █             ███                          ███             █                   █"
	@echo "          █                   █          ███                                ███          █                   █"
	@echo "          █                   █         ███                                  ▓██         █                   █"
	@echo "          █                   █         █  ███                            ███  █         █                   █"
	@echo "          █                   █         █     ███                      ███     █         █                   █"
	@echo "          ███                 █         █         ██                ███        █         █                 ███"
	@echo "             ███              █         █            ██          ██            █         █              ███   "
	@echo "                ███           █         █               ██    ██               █         █           ███      "
	@echo "                   ███        █       ░██                  ██                  ███       █        ███         "
	@echo "               ███     ███    █    ███  █                   █                  █  ███    █     ██     ███     "
	@echo "            ███           ███ █ ███     █                   █                  █     ███ █ ███           ███  "
	@echo "          ██                 ██         █                   █                  █         ██                 ██"
	@echo "          █  ██                         █                   █                  █                         ██  █"
	@echo "          █     ██                      █                   █                  █                      ██     █"
	@echo "          █        ███                 ██▒                  █                  ██                 ███        █"
	@echo "          █           ███           ███   ███               █               ██   ███           ███           █"
	@echo "          █              ███     ██          ███            █           ███          ██     ███              █"
	@echo "          █                 ░███                ███         █        ███                ████                 █"
	@echo "          █                   █               ███  ███      █     ███  ███               █                   █"
	@echo "          █                   █            ███         ██   █  ██         ░██            █                   █"
	@echo "          █                   █         ██                ████                ██         █                   █"
	@echo "          ▒                   █         ████                                ████         █                   █"
	@echo "          █                   █         █   ▒██                          ███   █         █                   █"
	@echo "          █                   █         █       ██                    ██▓      █         █                   █"
	@echo "           ███                █         █          ███            ███          █         █                ███ "
	@echo "              ███             █         █             ███      ███             █         █             ███    "
	@echo "                  ██          █         █                ██████                █         █          ██        "
	@echo "                     ███      █      ████                   █                  ████      █      ▒██           "
	@echo "                        ███   █   ███   █                   █                  █   ███   █   ░██              "
	@echo "                           ██████       █                   █                  █       ██████                 "
	@echo "                                        █                   █                  █                              "
	@echo "                                        █                   █                  █                              "
	@echo "                                        █                   █                  █                              "
	@echo "                                        ███                 █                ▓██                              "
	@echo "                                           ███              █             ███                                 "
	@echo "                                              ███           █          ███                                    "
	@echo "                                                  ██        █       ███                                       "
	@echo "                                                     ██▒    █    ██                                           "
	@echo "                                                        ██▒ █ ██                                              "
	@echo '                       ____          _ _                                       ____             _ '
	@echo '                      / ___|___  ___(_) | ___                                 |  _ \ __ _ _   _| |'
	@echo '                     | |   / _ \/ __| | |/ _ \                                | |_) / _` | | | | |'
	@echo '                     | |__|  __/ (__| | |  __/                                |  __/ (_| | |_| | |'
	@echo '                      \____\___|\___|_|_|\___|                                |_|   \__,_|\__,_|_|'
	@echo ""
	@echo ""
	@echo "███████╗ ██████╗ ██████╗  ██████╗███████╗    ███████╗████████╗    ██╗  ██╗ ██████╗ ███╗   ██╗███╗   ██╗███████╗██╗   ██╗██████╗ "
	@echo "██╔════╝██╔═══██╗██╔══██╗██╔════╝██╔════╝    ██╔════╝╚══██╔══╝    ██║  ██║██╔═══██╗████╗  ██║████╗  ██║██╔════╝██║   ██║██╔══██╗"
	@echo "█████╗  ██║   ██║██████╔╝██║     █████╗      █████╗     ██║       ███████║██║   ██║██╔██╗ ██║██╔██╗ ██║█████╗  ██║   ██║██████╔╝"
	@echo "██╔══╝  ██║   ██║██╔══██╗██║     ██╔══╝      ██╔══╝     ██║       ██╔══██║██║   ██║██║╚██╗██║██║╚██╗██║██╔══╝  ██║   ██║██╔══██╗"
	@echo "██║     ╚██████╔╝██║  ██║╚██████╗███████╗    ███████╗   ██║       ██║  ██║╚██████╔╝██║ ╚████║██║ ╚████║███████╗╚██████╔╝██║  ██║"
	@echo "╚═╝      ╚═════╝ ╚═╝  ╚═╝ ╚═════╝╚══════╝    ╚══════╝   ╚═╝       ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚═╝  ╚═══╝╚══════╝ ╚═════╝ ╚═╝  ╚═╝"
	@echo "${WHITE}"






.PHONY : fclean re all header clean lib init
