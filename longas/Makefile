SRCS	=	map.c get_next_line.c get_next_line_utils.c gest_err.c moving.c ft_putnbr_fd.c so_long_utils.c check_wall.c key_hook.c so_long_utils_2.c check_staff.c check_more_staff.c so_long_utils_3.c
OBJS	=	${SRCS:.c=.o}
NAME	=	so_long
CC		=	gcc
RM		=	rm -f
CFLAGS	=	-Wall -Wextra -Werror -Imlx
all:	${NAME}
%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@
$(NAME):	${OBJS}
	$(CC) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
clean:
	${RM} ${OBJS}
fclean:
	${RM} ${NAME}
re: fclean all
.PHONY: all clean fclean re
