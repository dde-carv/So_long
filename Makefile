# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/17 13:39:50 by dde-carv          #+#    #+#              #
#    Updated: 2024/09/17 14:45:58 by dde-carv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

LIBFT	=	./libft/libft.a
INC	=	inc/
SRC_DIR	=	src/
OBJ_DIR	=	obj/
SRCB_DIR	=	src_b/
OBJB_DIR	=	obj_b/

CC	=	@gcc
CFLAGS	=	-Wall -Werror -Wextra -g -I
RM	=	@rm -f

_DIR	=	$(SRC_DIR)

SRCS	=	$()

OBJS	=	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

$(LIBFT):
		@make -s -C ./libft

$(NAME):	$(OBJS) $(LIBFT)
		@echo "Make .o and push_swap."
		@$(CC) $(CFLAGS) $(INC) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
		@mkdir -p $(@D)
		@$(CC) $(CFLAGS) $(INC) -c $< -o $@

all:		$(NAME)

clean:
		$(RM) -r $(OBJ_DIR)
		@make -s clean -C ./libft
		@echo "Clean .o files."

fclean:		clean
		$(RM) $(NAME)
		$(RM) $(NAME_B)
		@make -s fclean -C ./libft
		@echo "Clean exacuteble/s."

re:		fclean all

.PHONY:		all clean fclean re
