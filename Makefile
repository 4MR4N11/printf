SRCS =	_printf.c\
		print_bin.c\
		print_num.c\
		_putstr.c

NAME = libftprintf.a

OBJECT = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror 

all : $(NAME)

$(NAME) : $(OBJECT)
			ar rcs $(NAME) $(OBJECT)

%.o : %.c
			cc $(FLAGS) -c $<

clean :
			rm -rf $(OBJECT)
			rm -rf $(OBJECTB)

fclean : clean
			rm -rf $(NAME)

re : fclean all