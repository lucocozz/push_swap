NAME= 	libft.a

INT=	ft_atoll.c

STR=	ft_strlen.c			ft_isnumber.c		ft_strcmp.c

FILE=	ft_putchar.c		ft_putstr.c			ft_putnbr.c				\
		gnl.c

PILE=	ft_create_elem.c	ft_pile_at.c		ft_pile_push_front.c	\
		ft_pile_clear.c		ft_pile_last.c		ft_pile_push_back.c		\
		ft_pile_merge.c		ft_pile_reverse.c	ft_pile_size.c			\
		ft_pile_print.c		ft_pile_push_back_if_not.c


SRCS=	$(addprefix integer/, $(INT)) $(addprefix file/, $(FILE))		\
		$(addprefix pile/, $(PILE)) $(addprefix string/, $(STR))

OBJS_S= $(SRCS:%.c=%.o)

CC= clang

CFLAGS= -Wall -Wextra -Werror -I ./includes #-g3 -fsanitize=address

all: $(NAME)

$(NAME): $(OBJS_S)
	ar -rcs $(NAME) $(OBJS_S)

clean:
	rm -f $(OBJS_S)

fclean: clean
	rm -f $(NAME)

re: fclean all
