# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhaddar <yhaddar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/27 11:17:27 by yhaddar           #+#    #+#              #
#    Updated: 2017/10/26 17:47:18 by yhaddar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		fractol
CC =		@gcc
CFLAGS =	-Wall -Wextra -Werror
MLX =		-lmlx -framework OpenGL -framework Appkit -L$(MLX_PATH)

SRCS =		./src/burningship.c \
			./src/error.c \
			./src/init.c \
			./src/julia.c \
			./src/keyhook.c \
			./src/main.c \
			./src/mandelbrot.c \
			./src/mousehook.c \
			./src/mousemotion.c \
			./src/pix_to_img.c \
			./src/tools.c \

OBJS =		$(SRCS:.c=.o)

INCL = ./include
MLX_PATH =	./mlx
LIBFT_PATH =./libft
LIBFT = -L./libft -lft

all:	$(NAME)

$(NAME):	$(OBJS)
	@make -C $(LIBFT_PATH)
	@make -C $(MLX_PATH)
	$(CC) $(CFLAG) $(SRCS) $(MLX) $(LIBFT) -I$(INCL) -o $(NAME)
	@echo "Fract'ol built"

clean:
	@rm -f $(OBJS)
	@make -C $(LIBFT_PATH) clean
	@make -C $(MLX_PATH) clean

fclean:	clean
	@rm -f $(NAME)
	@make -C $(LIBFT_PATH) fclean

re:	fclean all

.PHONY: all clean fclean re
