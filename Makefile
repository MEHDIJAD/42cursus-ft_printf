SRCS		= ft_printf.c \
			  print_utils/ft_tools.c \
			  print_utils/ft_utils.c \
			  print_utils/ft_printchar.c \
			  print_utils/ft_printstr.c \
			  print_utils/ft_printdigit.c \
			  print_utils/ft_printaddress.c \
			  print_utils/ft_printunsigned.c \
			  print_utils/ft_printhex.c \
			  print_utils/ft_print_percentage.c  \


OBJS		= ${SRCS:.c=.o}

NAME		= libftprintf.a
LIBC 		= ar rc
CC 			= cc
RM 			= rm -f
CFLAGS 		= -Wall -Wextra -Werror

all:		${NAME}

$(NAME):	${OBJS} ft_printf.h

%.o: %.c ft_printf.h
			${CC} ${CFLAGS} -I. -c $< -o $@
			${LIBC} ${NAME} $@

bonus: all

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
