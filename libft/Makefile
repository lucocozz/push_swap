NAME= 	libft.a

INT=	ft_atoll.c
STR=	ft_strlen.c			ft_isnumber.c		ft_strcmp.c
FILE=	ft_putchar.c		ft_putstr.c			ft_putnbr.c					\
		gnl.c
PILE=	ft_clear_stacks.c	ft_create_elem.c	ft_pile_clear.c				\
		ft_pile_contain.c	ft_pile_print.c		ft_pile_push_back_if_not.c	\
		ft_pile_push_back.c	ft_pile_size.c		ft_pile_push_front.c		\
		ft_pile_sort_insert.c

SRCS=	$(INT) $(FILE) $(STR) $(PILE)
OBJS= $(SRCS:%.c=$(OBJS_DIR)/%.o)
OBJS_DIR= .objs
DEPENDENCIES= $(OBJS:%.o=%.d)
INCLUDES_DIR = includes $(LIBS:%=lib%/includes)
LIBS = gc

CC= clang
MKDIR= mkdir -p
RM= rm -f

CFLAGS= -Wall -Wextra -Werror -MMD
CXXFLAGS= -I includes $(INCLUDES_DIR:%=-I ../%)

vpath %.c integer string file pile

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

-include $(DEPENDENCIES)
$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(CXXFLAGS) -c $< -o $@

$(OBJS_DIR):
	$(MKDIR) $(OBJS_DIR)

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
