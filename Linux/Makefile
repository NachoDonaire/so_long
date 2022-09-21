SRCS	=	./src/main.c ./GNL/get_next_line.c ./GNL/get_next_line_utils.c ./src/gest_err.c ./src/moving.c ./src/ft_putnbr_fd.c ./src/so_long_utils.c ./src/check_wall.c ./src/key_hook.c ./src/so_long_utils_2.c ./src/check_staff.c ./src/check_more_staff.c ./src/so_long_utils_3.c
OBJS	=	${SRCS:.c=.o}
NAME	=	so_long
CC		=	gcc
RM		=	rm -f
CFLAGS	=	-Wall -Wextra -Werror -Imlx
all:	${NAME}
%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@
#(mac)	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@
$(NAME):	${OBJS}
#(mac)	$(CC) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	$(CC) $(OBJS) -Lmlx -lmlx_Linux -L/usr/local/lib -lXext -lX11 -lm -lz -o $(NAME)
clean:
	${RM} ${OBJS}
fclean: clean
	${RM} ${NAME}
re: fclean clean all
.PHONY: all clean fclean re
