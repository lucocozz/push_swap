CHECKER_NAME= checker

PUSH_SWAP_NAME= push_swap

CHECKER_SRCS=	main.c

PUSH_SWAP_SRCS=	main.c	ft_sorting.c	ft_sorting2.c

GLOBAL_SRCS=	ft_parsing.c	sort_list.c		sort.c		sort2.c		\
				sort3.c

CHECKER= $(addprefix checker_file/, $(CHECKER_SRCS))

PUSH_SWAP= $(addprefix push_swap_file/, $(PUSH_SWAP_SRCS))

GLOBAL= $(addprefix global_file/, $(GLOBAL_SRCS))

CC=		clang

CFLAGS= -Wall -Wextra -Werror -I includes/ -I libft/includes/ -L libft/ -lft	\
		-L libgc/ -lgc -I libgc/includes/


all: lib $(CHECKER_NAME) $(PUSH_SWAP_NAME)

lib:
	$(MAKE) -C libgc
	$(MAKE) -C libft

$(CHECKER_NAME):
	$(CC) $(CHECKER) $(GLOBAL) -o $(CHECKER_NAME) $(CFLAGS) $(INCL)

$(PUSH_SWAP_NAME):
	$(CC) $(PUSH_SWAP) $(GLOBAL) -o $(PUSH_SWAP_NAME) $(CFLAGS) $(INCL)

clean:
	rm -f $(CHECKER_OBJS)
	rm -f $(PUSH_SWAP_OBJS)
	$(MAKE) clean -C libft
	$(MAKE) clean -C libgc

fclean:
	rm -f $(CHECKER_NAME) $(CHECKER_OBJS)
	rm -f $(PUSH_SWAP_NAME) $(PUSH_SWAP_OBJS)
	$(MAKE) fclean -C libft
	$(MAKE) fclean -C libgc

re: fclean all
