NAME =cub3D

SRCS = test.c

OBJS =$(SRCS:.c=.o)
CUBIO = mlx_linux/libmlx.a
CC = clang
CFLAGS = -lXext -lX11 -lm -lbsd
INCLUDE = -I mlx_linux

RM = rm -rf

all: $(NAME)

%.o : %.c
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} ${INCLUDE}

$(NAME): $(OBJS)
		make -C mlx_linux -f Makefile
		${CC} ${CFLAGS} ${OBJS} ${CUBIO} ${INCLUDE} -o ${NAME}
clean: 
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all
