# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/17 13:39:50 by dde-carv          #+#    #+#              #
#    Updated: 2024/09/24 11:26:35 by dde-carv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

LIBFT	=	./libft/libft.a
MLX		=	./minilibx-linux/libmlx.a
INC		=	inc/
SRC_DIR	=	src/
OBJ_DIR	=	obj/

CC	=	@cc
CFLAGS	=	-Wall -Werror -Wextra
MLXFLAGS	=	-Lminilibx-linux -Imlx_linux -lXext -lX11 -lm -lz
RM	=	@rm -f

SO_LONG_DIR	=	$(SRC_DIR)so_long/main.c \
				$(SRC_DIR)so_long/so_long_utils.c

SRCS	=	$(SO_LONG_DIR)

OBJS	=	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

$(LIBFT):
		@make -s -C ./libft

$(MLX):
		@make -s -C ./minilibx-linux

$(NAME):	$(OBJS) $(LIBFT) $(MLX)
		@echo "Make .o and so_long."
		@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLXFLAGS) $(MLX) -o $(NAME)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
		@mkdir -p $(@D)
		@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

all:		$(NAME)

clean:
		$(RM) -r $(OBJ_DIR)
		@make -s clean -C ./libft
		@make -s clean -C ./minilibx-linux
		@echo "Clean .o files."

fclean:		clean
		$(RM) $(NAME)
		@make -s fclean -C ./libft
		@echo "Clean exacuteble/s."

re:		fclean all

.PHONY:		all clean fclean re