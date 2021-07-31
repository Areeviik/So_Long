SRCS = 	start.c\
		map.c\
		move.c\
		utils.c\
		draw.c\
		check.c\


OBJS = ${SRCS:.c=.o}

NAME = so_long

CC = gcc

MLXFLAG = -lmlx -framework OpenGL -framework AppKit

all: ${NAME}

${NAME} : ${ONJS}
	${CC} ${MLXFLAG} libmlx.dylib ${SRCS} libft.a -o ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY : all clean fclean re
