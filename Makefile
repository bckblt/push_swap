NAME    = push_swap

SRCS    = push_swap.c utils.c ft_check.c list_cfg.c actions.c stcmove.c bckblts_sort_alg.c radix.c ft_makeone.c utils_vers2.c

OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean: 
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re