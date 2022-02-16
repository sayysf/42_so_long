# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysay <ysay@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 15:44:43 by ysay              #+#    #+#              #
#    Updated: 2022/02/09 09:25:34 by ysay             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= so_long

_SRC= main.c map.c map_check.c obj.c image.c anime.c mov.c in0.c in1.c in2.c in3.c in4.c in5.c inx.c render.c
_OBJ= $(_SRC:.c=.o)
_EXLIB= libft.a
_EXLIB2= libmlx.a
_IDIR= ./mlx ./ ./maps/libft

SDIR= ./
ODIR= ./
EXLIBD=maps/libft/
EXLIBD2=mlx/
IFLAG= -I

SRC= $(patsubst %,$(SDIR)%,$(_SRC))
OBJ= $(patsubst %,$(ODIR)%,$(_OBJ))
EXLIB= $(patsubst %,$(EXLIBD)%,$(_EXLIB))
EXLIB2= $(patsubst %,$(EXLIBD2)%,$(_EXLIB2))
INC= $(patsubst %,$(IFLAG)%,$(_IDIR))

CC=gcc

FLAGS= -Wall -Wextra -Werror

.PHONY: all clean fcelan re

all: $(NAME)

$(NAME): $(OBJ) $(EXLIB) $(EXLIB2)
	$(CC) $(FLAGS) $(INC) $(OBJ)  $(EXLIB) $(EXLIB2) -framework OpenGL -framework AppKit -o $@
$(ODIR)%.o : $(SDIR)%.c 
	$(CC) $(FLAGS) $(INC) -Imlx -c  $< -o $@

$(EXLIB) :
	make -C $(EXLIBD)

clean:
	rm -rf $(OBJ)
	make clean -C $(EXLIBD)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(EXLIBD)

re: fclean all
